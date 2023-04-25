#pragma once

#include <iostream>

int logInOrSignUp()
{
    int logInOrSignUp;

    std::cout << "Welcome to simple_crud!" << std::endl;
    std::cout << "(1) Log in" << std::endl
              << "(2) Sign up" << std::endl
              << "Chose and option: ";

    std::cin >> logInOrSignUp;
    return logInOrSignUp;
}