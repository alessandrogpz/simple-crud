#include "../headers/password.h"

std::string SetPassword()
{
    std::string password{"0"};
    std::string r_password{"1"};

    while (password != r_password)
    {
        std::cout << "New password: ";
        std::cin >> password;
        std::cout << "Repeat password: ";
        std::cin >> r_password;

        if (password == r_password)
        {
            return password + "\n";
        }
        else
        {
            std::cout << "Password must match. Try again.\n";
        }
    }

    return ""; // handle the case when the while loop is never executed
}
