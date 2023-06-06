#include "../headers/login.h"
#include "../headers/password.h"
#include "../headers/checks.h"
#include "../headers/user_data.h"
#include "../headers/read.h"
#include "../headers/menu_options.h"

bool UserLogIn()
{
    char confirmation;

    // Check if filename exists and password match.

    while (true)
    {
        // Log in attempt.
        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        if (!(CheckIfUserExists(username)) || !(passwordAuthenticate(password)))
        {
            std::cout << "---------------------------------------" << std::endl;
            std::cout << "Username or password do not match" << std::endl;
            std::cout << "Quit loggin? (y/n) ";
            std::cin >> confirmation;

            if (confirmation == 'y' || confirmation == 'Y')
            {
                return false;
            }
        }
        else
        {
            break;
        }
    }

    // Logging in successful.
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Successful authentication" << std::endl;
    std::cout << "Loggin in..." << std::endl;
    return true;
}