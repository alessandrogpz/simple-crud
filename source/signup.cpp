#include "../headers/signup.h"
#include "../headers/checks.h"
#include "../headers/user_data.h"
#include "../headers/users.h"

void getUserInfo()
{
    firstName = getValidStringLettersOnly("What is your first name?: ");
    lastName = getValidStringLettersOnly("what is your last name?: ");
    age = getValidInt("Waht is your age? ");
    eMail = getValidEmail("What is your e-mail?: ");
}

int getValidInt(std::string prompt)
{
    std::cout << prompt;

    int num;
    while (true)
    {
        std::cout << "Enter an integer: ";
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

bool isValidEmail(const std::string &email)
{
    // Regular expression for a valid email address
    const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    // Check if the email matches the pattern
    return std::regex_match(email, pattern);
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

void UserSignUp()
{
    // Sign up
    {
        extern std::string foldername;
        extern std::string username;
        extern std::string createAccount;
        extern std::string username;

        if (UserExists(foldername + username + ".txt"))
        {
            std::cout << "This username is not available." << std::endl;
        }
        else
        {
            std::cout << foldername + username + ".txt" << std::endl;
            std::cout << "Would you like to create a new account as \"" << username << "\" ? ( y / n ): ";
            std::cin >> createAccount;

            if (createAccount == "y")
            {
                getUserInfo();
                User usr(username, firstName, lastName, age, eMail);
            }
        }
    }
}