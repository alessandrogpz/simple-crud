#include "../headers/login.h"
#include "../headers/users.h"
#include "../headers/signup.h"
#include "../headers/password.h"

std::string foldername = "../user_database/";
std::string username;
std::string content;
std::string createAccount;

// Checks if file already exists
bool UserExists(const std::string &filename)
{
    std::ifstream infile(filename);
    return infile.good();
}

void UserLogIn()
{

    std::cout << "Username: ";
    std::cin >> username;

    if (UserExists(foldername + username))
    {
        // type password
    }
    else
    {
        std::cout << "Would you like to create a new account as \"" << username << "\" ? ( y / n ): ";
        std::cin >> createAccount;

        if (createAccount == "y")
        {
            getUserInfo();
            User usr(username, firstName, lastName, age, eMail);
        }
    }
}