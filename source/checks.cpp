#include "../headers/checks.h"
#include "../headers/password.h"
#include "../headers/read.h"
#include "../headers/user_data.h"

// Checks if file already exists
bool CheckIfUserExists(const std::string &filename)
{
    std::ifstream infile(filename);
    return infile.good();
}

bool isValidEmail(const std::string &email)
{
    // Regular expression for a valid email address
    const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    // Check if the email matches the pattern
    return std::regex_match(email, pattern);
}

bool passwordAuthenticate(const std::string &password)
{
    extern std::string foldername;
    extern std::string username;

    return hashPassword(password) == readCurrentHashPassword(foldername + username + ".txt");
}