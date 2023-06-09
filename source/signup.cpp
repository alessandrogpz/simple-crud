#include "../headers/signup.h"
#include "../headers/checks.h"
#include "../headers/user_data.h"
#include "../headers/users.h"
#include "../headers/password.h"

void getUserInfo()
{
    password = hashPassword(setPassword());
    firstName = getValidStringLettersOnly("What is your first name?: ");
    lastName = getValidStringLettersOnly("what is your last name?: ");
    age = getValidInt("Waht is your age? ");
    eMail = hashPassword(getValidEmail("What is your e-mail?: "));
}

int getValidInt(std::string prompt)
{
    std::cout << prompt;

    int num;
    while (true)
    {
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();                                                   // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore invalid input
            std::cout << "Invalid input. ";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any extra input
            return num;
        }
    }
}

std::string getValidStringLettersOnly(std::string prompt)
{
    std::string input;
    bool isValid = false;

    std::cout << prompt;

    while (!isValid)
    {
        std::cin >> input;

        // Check if input contains only letters
        bool allLetters = true;
        for (char c : input)
        {
            if (!std::isalpha(c))
            {
                allLetters = false;
                break;
            }
        }

        if (allLetters)
        {
            isValid = true;
        }
        else
        {
            std::cout << "Invalid input. Please enter letters only: ";
        }
    }

    return input;
}

std::string getValidEmail(std::string prompt)
{
    std::string email;
    bool isValid = false;

    std::cout << prompt;

    while (!isValid)
    {
        std::cin >> email;

        if (isValidEmail(email))
        {
            isValid = true;
        }
        else
        {
            std::cout << "Invalid email address. Try again: ";
        }
    }
    return email;
}

bool UserSignUp()
{
    // Sign up new user
    {
        std::cout << "Username: ";
        std::cin >> username;

        while (CheckIfUserExists(username))
        {
            std::cout << "This username is not available. Try another." << std::endl;

            std::cout << "Username: ";
            std::cin >> username;
        }

        // Create new user
        getUserInfo();
        User usr(username, password, firstName, lastName, age, eMail);
        return true;
    }
}