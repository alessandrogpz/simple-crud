#include "../headers/login.h"
#include "../headers/password.h"
#include "../headers/checks.h"
#include "../headers/user_data.h"
#include "../headers/read.h"
#include "../headers/menu_options.h"

bool UserLogIn()
{
    // Log in attempt.
    std::cout << "Username: ";
    std::cin >> username;

    {
        // Check if filename already exists.
        while (!(CheckIfUserExists(foldername + username + ".txt")))
        {
            std::cout << "Username '" + username + "' does not exist." << std::endl;
            exitOrContinueProgram();

            std::cout << "Username: ";
            std::cin >> username;
        }

        // Username exists.
        // Password autentication attempt for said username.
        std::cout << "Password: ";
        std::cin >> password;

        // Check if stored hashed password match typed password.
        while (!(passwordAuthenticate(password)))
        {
            std::cout << "Password do not match." << std::endl;
            std::cout << "Password: ";
            std::cin >> password;
        }

        // Password autenticated.
        // Logging in.
        std::cout << "Login successfully" << std::endl;
        std::cout << "Loggin in..." << std::endl;
        return true;
    }
}