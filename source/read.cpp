#include "../headers/read.h"
#include "../headers/user_data.h"
#include "../headers/database_utils.h"

int readUserContentFile(const std::string &username)
/* Reads and prints the content user located in user_content_files*/

{
    // Specify the full path of the database file
    const std::string db_Path = "../user_database/user_database.db";

    // Open the database
    sqlite3 *db = openDatabase(db_Path);
    if (!db)
    {
        return 1; // 1 to indicate failure
    }

    // Prepare the select statement
    const std::string selectSql = "SELECT content_link FROM users WHERE username = ?";
    sqlite3_stmt *stmt = prepareStatement(db, selectSql);

    if (!stmt)
    {
        closeDatabase(db);
        return 1; // 1 to indicate failure
    }

    // Bind the username value to the prepared statement parameter
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    // Execute the prepared statement
    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        // Retrieve the content_link value
        const unsigned char *contentLink = sqlite3_column_text(stmt, 0);

        // Construct the file path
        std::string filePath = "../user_database/user_content_files/" + std::string(reinterpret_cast<const char *>(contentLink));

        // Check if the file exists
        std::ifstream file(filePath);
        if (file)
        {
            // Read and process the file content
            std::cout << "---------------------------------------" << std::endl;
            std::cout << "Loading file ..." << std::endl;
            std::cout << "Reading file: '" + username + "'" << std::endl;
            std::cout << "---------------- Content --------------" << std::endl;

            std::string line;
            while (std::getline(file, line))
            {
                // Process input
                std::cout << line << std::endl;
            }

            // Close the file

            std::cout << "---------------------------------------" << std::endl;

            // Close the file
            file.close();
        }
        else
        {
            std::cerr << "File not found: " << filePath << std::endl;
        }
    }
    else
    {
        std::cerr << "User not found: " << username << std::endl;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

    // Close the database
    closeDatabase(db);

    return 0;
}

std::string readUserHashPassword(const std::string &username)
{
    // Specify the full path of the database file
    const std::string db_Path = "../user_database/user_database.db";

    // Open the database
    sqlite3 *db = openDatabase(db_Path);
    if (!db)
    {
        return ""; // Return an empty string to indicate failure
    }

    // Prepare the select statement
    const std::string selectSql = "SELECT password FROM users WHERE username = ?";

    sqlite3_stmt *stmt = prepareStatement(db, selectSql);
    if (!stmt)
    {
        closeDatabase(db);
        return ""; // Return an empty string to indicate failure
    }

    // Bind the username value to the prepared statement parameter
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

    // Execute the prepared statement
    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        const unsigned char *password = sqlite3_column_text(stmt, 0);
        std::string hashedPassword(reinterpret_cast<const char *>(password));

        // Finalize the statement
        sqlite3_finalize(stmt);

        // Close the database
        closeDatabase(db);

        return hashedPassword;
    }
    else
    {
        std::cerr << "User not found: " << username << std::endl;

        // Finalize the statement
        sqlite3_finalize(stmt);

        // Close the database
        closeDatabase(db);
        return ""; // Return an empty string to indicate failure
    }
}
