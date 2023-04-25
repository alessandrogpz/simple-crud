#include "../headers/checks.h"

// Checks if file already exists
bool UserExists(const std::string &filename)
{
    std::ifstream infile(filename);
    return infile.good();
}