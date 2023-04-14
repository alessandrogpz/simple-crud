#include "../headers/signup.h"

void getUserInfo()
{
    std::cout << "What is your first name?: ";
    std::cin >> firstName;

    std::cout << "what is your last name?: ";
    std::cin >> lastName;

    std::cout << "Waht is your age?: ";
    std::cin >> age;

    std::cout << "What is your e-mail?: ";
    std::cin >> eMail;
}