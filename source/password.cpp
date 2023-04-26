#include "../headers/password.h"

std::string setPassword()
{
    std::string password, confirmPassword;
    bool match = false;

    do
    {
        std::cout << "Set your password: ";
        std::cin >> password;

        std::cout << "Confirm your password: ";
        std::cin >> confirmPassword;

        if (password == confirmPassword)
        {
            match = true;
            std::cout << "Password set successfully!" << std::endl;
        }
        else
        {
            std::cout << "Passwords do not match. Please try again." << std::endl;
        }

    } while (!match);

    return password;
}

std::string hashPassword(const std::string &password)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    std::string hashedPassword((char *)hash, SHA256_DIGEST_LENGTH);
    return hashedPassword;
}
