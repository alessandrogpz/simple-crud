#include "../headers/menu_options.h"

Event logInOrSignUp()
{
    int userChoice;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Welcome to simple_crud!" << std::endl;
    std::cout << "(1) Log in" << std::endl
              << "(2) Sign up" << std::endl
              << "(3) Exit Program" << std::endl
              << "Chose and option: ";

    std::cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        return Event::LOGIN;
    case 2:
        return Event::SIGNUP;
    case 3:
        return Event::EXIT;
    default:
        return Event::INVALID;
    }
}

void invalidInput()
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Invalid Input" << std::endl;
}

Event writeReadOrDelete(std::string username)
{
    int userChoice;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Logged in as: '" + username + "'" << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "(1) Read" << std::endl
              << "(2) Write" << std::endl
              << "(3) Delete Files" << std::endl
              << "(4) Delete User & Files" << std::endl
              << "(5) Log out" << std::endl
              << "Choose an option: ";

    std::cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        return Event::READ;
    case 2:
        return Event::WRITE;
    case 3:
        return Event::DELETE_FILES;
    case 4:
        return Event::DELETE_USER;
    case 5:
        return Event::LOGOUT;
    default:
        return Event::INVALID;
    }
}

void exitProgram()
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Exiting program ..." << std::endl;
    exit(0);
}