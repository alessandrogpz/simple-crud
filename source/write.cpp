#include "../headers/write.h"

void addNewUserToDB(const std::string &username, const std::string &password, const std::string &name, int age, const std::string &email, const std::string &role, const std::string &contentLink)
{
    sqlite3 *db;
    char *err_msg = nullptr;

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

    // Create the table if it doesn't exist
    const char *create_table_sql = "CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT, name TEXT, age INTEGER, email TEXT, role TEXT, content_link TEXT);";
    rc = sqlite3_exec(db, create_table_sql, nullptr, nullptr, &err_msg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error creating table: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return;
    }

    // Prepare the insert statement
    const char *insert_sql = "INSERT INTO users (username, password, name, age, email, role, content_link) VALUES (?, ?, ?, ?, ?, ?, ?);";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, insert_sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Bind the values to the prepared statement parameters
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, age);
    sqlite3_bind_text(stmt, 5, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, role.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, contentLink.c_str(), -1, SQLITE_STATIC);

    // Execute the prepared statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    // Finalize the statement
    sqlite3_finalize(stmt);

    // Close the database
    sqlite3_close(db);

    std::cout << "User data inserted successfully." << std::endl;
}

int createUserContentFile(std::string filename)
{

    // Open input file for writing (create a new file)
    std::ofstream outfile(filename);

    // Check if the file was opened successfully
    if (!outfile.is_open())
    {
        std::cout << "Error opening file " << filename << " for writing " << std::endl;
        return 1;
    }

    // Close input file
    outfile.close();
    return 0;
}

int appendOnFile(std::string filename)
{
    /*
    This is a function that appends user input to a file.
    It opens the file for writing (appending), and if the file is not opened successfully, it displays an error message and returns 1.
    The function then loops until the user enters three consecutive empty lines, indicating that they have finished entering text.
    It reads user input from the console and appends it to a string called "content".
    If the user enters an empty line, the function increments a counter of empty lines.
    If the user enters a non-empty line, the function adds the line to the "content" string and resets the counter of empty lines.
    Finally, the function writes the "content" string to the file and returns 0.
    */

    // Open input file for writing (appending)
    std::ofstream outfile(filename, std::ios::app);

    // Check if the file was opened successfully
    if (!outfile.is_open())
    {
        std::cout << "Error opening file " << filename << " for appending " << std::endl;
        return 1;
    }

    std::string content;

    // loop until three consecutive empty lines are entered
    int empty_lines = 0;
    while (empty_lines < 2)
    {
        std::string line;
        std::getline(std::cin, line);

        // check if the line is empty
        if (line.empty())
        {
            empty_lines++;
            content += "\n";
        }
        else
        {
            // add the line to the content string
            content += line + "\n";
            empty_lines = 0; // reset the count of empty lines
        }
    }

    // write the content to the file
    outfile << content;

    // Close input file
    outfile.close();
    return 0;
}
