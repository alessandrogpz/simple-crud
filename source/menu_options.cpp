#include "../headers/menu_options.h"

int logInOrSignUp()
{
    int userChoice;

    std::cout << "Welcome to simple_crud!" << std::endl;
    std::cout << "(1) Log in" << std::endl
              << "(2) Sign up" << std::endl
              << "Chose and option: ";

    std::cin >> userChoice;
    return userChoice;
}

void exitOrContinueProgram()
{
    int userChoice;

    std::cout << "Would you like to:" << std::endl;
    std::cout << "(1) Continue" << std::endl
              << "(2) Exit Program" << std::endl
              << "Chose an option: ";

    while (true)
    {
        std::cin >> userChoice;

        if (userChoice == 1)
        {
            std::cout << "Continuing program ..." << std::endl;
            break;
        }
        else if (userChoice == 2)
        {
            std::cout << "Exiting program..." << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "Invalid input. Try again: ";
        }
    }
}

int writeOrRead()
{
    int userChoice;

    std::cout << "Would you like to read or write in your file?" << std::endl;
    std::cout << "(1) Read" << std::endl
              << "(2) Write" << std::endl
              << "Chose and option: ";

    std::cin >> userChoice;
    return userChoice;
}