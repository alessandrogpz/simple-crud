#include "../headers/checks.h"
#include "../headers/password.h"
#include "../headers/read.h"
#include "../headers/user_data.h"
#include "../headers/database_utils.h"

// Checks if user already exists in DB
bool CheckIfUserExists(const std::string &username)
{
    // Specify the full path of the database file
    const std::string db_Path = "../user_database/user_database.db";

    // Open the database
    sqlite3 *db = openDatabase(db_Path);

    if (!db)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        closeDatabase(db);
        return false;
    }

    // Prepare the select statement
    const std::string select_sql = "SELECT username FROM users WHERE username = ?;";
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
        // User exists
        std::cout << "User already exists." << std::endl;

        // Finalize the statement
        sqlite3_finalize(stmt);

        // Close the database
        closeDatabase(db);

        return true;
    }
    else if (rc == SQLITE_DONE)
    {
        // User does not exist
        // Finalize the statement
        sqlite3_finalize(stmt);

        // Close the database
        closeDatabase(db);

        return false;
    }
    else
    {
        std::cerr << "Error executing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        closeDatabase(db);
        return false;
    }
}

// Check if user inserted email is of a valid format
bool isValidEmail(const std::string &email)
{
    // Regular expression for a valid email address
    const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    // Check if the email matches the pattern
    return std::regex_match(email, pattern);
}

// Check if user inserted password if the same as the one stored in the database
bool passwordAuthenticate(const std::string &password)
{
    extern std::string username;

    return hashPassword(password) == readUserHashPassword(username);
}