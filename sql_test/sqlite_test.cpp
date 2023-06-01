#include <iostream>
#include <sqlite3.h>

using namespace std;

int main()
{
    sqlite3 *db;
    char *err_msg = nullptr;

    // Specify the full path of the database file
    const char *db_path = "../user_database/database.db";

    // open the database
    int rc = sqlite3_open(db_path, &db);
    if (rc != SQLITE_OK)
    {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }

    // create a table
    const char *create_table_sql = "CREATE TABLE contacts (id INTEGER PRIMARY KEY, name TEXT, phone TEXT, address TEXT);";
    rc = sqlite3_exec(db, create_table_sql, nullptr, nullptr, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error creating table: " << err_msg << endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // insert some data
    const char *insert_sql = "INSERT INTO contacts (name, phone, address) VALUES ('John Doe', '555-1234', 'Los Angeles');";
    rc = sqlite3_exec(db, insert_sql, nullptr, nullptr, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error inserting data: " << err_msg << endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // select some data
    const char *select_sql = "SELECT * FROM contacts;";
    rc = sqlite3_exec(
        db, select_sql, [](void *data, int argc, char **argv, char **col_names) -> int
        {
        for (int i = 0; i < argc; ++i) {
            cout << col_names[i] << ": " << argv[i] << endl;
        }
        cout << endl;
        return 0; },
        nullptr, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error selecting data: " << err_msg << endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    // close the database
    sqlite3_close(db);

    return 0;
}
