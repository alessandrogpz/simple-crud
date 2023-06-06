#pragma once

#include <iostream>
#include <sqlite3.h>

sqlite3 *openDatabase(const std::string &dbPath);
sqlite3_stmt *prepareStatement(sqlite3 *db, const std::string &sql);
void closeDatabase(sqlite3 *db);
