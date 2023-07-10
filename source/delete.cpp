#include "../headers/delete.h"
#include "../headers/database_utils.h"

bool deleteUserContentFile(const std::string &username)
{
    std::cout << "Are you sure you want to delete all '" << username << "' files? (y/n) ";
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'y' || confirmation == 'Y')
    {
        // Specify the full path of the database file
        const std::string dbPath = "../user_database/user_database.db";

        // Open the database
        sqlite3 *db = openDatabase(dbPath);
        if (!db)
        {
            std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        // Prepare the select statement
        const std::string select_sql = "SELECT content_link FROM users WHERE username = ?;";
        sqlite3_stmt *stmt = prepareStatement(db, select_sql);
        if (!stmt)
        {
            std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
            closeDatabase(db);
            return false;
        }

        // Bind the username value to the prepared statement parameter
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

        // Execute the prepared statement
        int rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW)
        {
            // Retrieve the content_link value
            const unsigned char *contentLink = sqlite3_column_text(stmt, 0);

            // Construct the full file path
            std::string filePath = "../user_database/user_content_files/" + std::string(reinterpret_cast<const char *>(contentLink));

            // Erase the file content
            std::ofstream file(filePath);
            if (file.is_open())
            {
                file.close();
                std::cout << "File content erased" << std::endl;
            }
            else
            {
                std::cout << "Error erasing file content" << std::endl;
                sqlite3_finalize(stmt);
                closeDatabase(db);
                return false;
            }
        }
        else
        {
            std::cerr << "User not found: " << username << std::endl;
            sqlite3_finalize(stmt);
            closeDatabase(db);
            return false;
        }

        // Finalize the statement
        sqlite3_finalize(stmt);

        // Close the database
        closeDatabase(db);

        return true;
    }
    else
    {
        std::cout << "File deletion cancelled" << std::endl;
        return false;
    }
}

bool deleteUserAccountAndUserContentFile(const std::string username)
{
    std::cout << "Are you sure you want to delete the '" << username << "' account and all its files? (y/n) ";
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'y' || confirmation == 'Y')
    {
        // Retrieve the content file name from the database
        const std::string dbPath = "../user_database/user_database.db";
        sqlite3 *db = openDatabase(dbPath);
        if (!db)
        {
            std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
            return false;
        }

        // Prepare the select statement
        const std::string select_sql = "SELECT content_link FROM users WHERE username = ?;";
        sqlite3_stmt *stmt = prepareStatement(db, select_sql);
        if (!stmt)
        {
            std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
            closeDatabase(db);
            return false;
        }

        // Bind the username value to the prepared statement parameter
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

        // Execute the prepared statement
        int rc = sqlite3_step(stmt);
        if (rc == SQLITE_ROW)
        {
            // Retrieve the content file name from the result
            const unsigned char *contentLink = sqlite3_column_text(stmt, 0);
            std::string filePath = "../user_database/user_content_files/" + std::string(reinterpret_cast<const char *>(contentLink));

            // Delete the content file
            if (std::remove(filePath.c_str()) != 0)
            {
                std::cout << "Error deleting file" << std::endl;
                sqlite3_finalize(stmt);
                closeDatabase(db);
                return false;
            }
            else
            {
                std::cout << "File successfully deleted" << std::endl;
            }
        }
        else
        {
            std::cerr << "User not found: " << username << std::endl;
            sqlite3_finalize(stmt);
            closeDatabase(db);
            return false;
        }

        // Delete the corresponding database entry
        const std::string delete_sql = "DELETE FROM users WHERE username = ?;";
        sqlite3_stmt *delete_stmt = prepareStatement(db, delete_sql);
        if (!delete_stmt)
        {
            std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(stmt);
            closeDatabase(db);
            return false;
        }

        // Bind the username value to the prepared statement parameter
        sqlite3_bind_text(delete_stmt, 1, username.c_str(), -1, SQLITE_STATIC);

        // Execute the delete statement
        rc = sqlite3_step(delete_stmt);
        if (rc != SQLITE_DONE)
        {
            std::cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_finalize(delete_stmt);
            sqlite3_finalize(stmt);
            closeDatabase(db);
            return false;
        }
        else
        {
            std::cout << "User successfully deleted" << std::endl;
        }

        // Finalize the statements
        sqlite3_finalize(delete_stmt);
        sqlite3_finalize(stmt);

        // Close the database
        closeDatabase(db);

        return true;
    }else
    {
        std::cout << "Account deletion cancelled" << std::endl;
        return false;
    }
}
