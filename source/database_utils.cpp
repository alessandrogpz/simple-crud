#include "../headers/database_utils.h"

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
