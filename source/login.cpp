#include "../headers/login.h"
#include "../headers/password.h"
#include "../headers/checks.h"
#include "../headers/user_data.h"

void UserLogIn()
{
    std::cout << "Username: ";
    std::cin >> username;
    // Log in
    {
        if (!(CheckIfUserExists(foldername + username + ".txt")))
        {
            std::cout << "This username does not exist." << std::endl;
        }
        else
        {
            // password()
        }
    }
}