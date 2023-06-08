#include "../headers/database_utils.h"

void createUsersTable(sqlite3 *db)
{
    // Specify the full path of the database file
    const char *db_path = "../user_database/user_database.db";

    // Open the database
    int rc = sqlite3_open(db_path, &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Create the SQL statement for creating the users table
    const char *sql = "CREATE TABLE IF NOT EXISTS users ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "username TEXT NOT NULL,"
                      "password TEXT NOT NULL,"
                      "name TEXT NOT NULL,"
                      "age INTEGER,"
                      "email TEXT NOT NULL,"
                      "role TEXT NOT NULL,"
                      "contentLink TEXT NOT NULL);";

    // Execute the SQL statement
    char *errMsg = nullptr;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error creating users table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

sqlite3 *openDatabase(const std::string &dbPath)
{
    sqlite3 *db;
    int rc = sqlite3_open(dbPath.c_str(), &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return nullptr;
    }
    return db;
}

sqlite3_stmt *prepareStatement(sqlite3 *db, const std::string &sql)
{
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return nullptr;
    }
    return stmt;
}

void closeDatabase(sqlite3 *db)
{
    sqlite3_close(db);
}
