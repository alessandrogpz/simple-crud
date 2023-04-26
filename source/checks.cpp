#include "../headers/checks.h"
#include "../headers/password.h"

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

// bool authenticate(const std::string &password)
// {
//     return hashPassword(password) == hashedPassword;
//