#include "../headers/login_or_signup.h"

int logInOrSignUp()
{
    int UserChoice;

    std::cout << "Welcome to simple_crud!" << std::endl;
    std::cout << "(1) Log in" << std::endl
              << "(2) Sign up" << std::endl
              << "Chose and option: ";

    std::cin >> UserChoice;
    return UserChoice;
}