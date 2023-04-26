#include "../headers/read.h"
#include "../headers/user_data.h"

int ReadFile(std::string filename)
{
    // Open input file for reading
    std::ifstream input(filename);

    // Check if the file was opened successfully
    if (!input.is_open())
    {
        std::cout << "Error opening file for reading " << filename << std::endl;
        return 1;
    }

    // Read input from file
    std::string line;
    while (getline(input, line))
    {
        // Process input
        std::cout << line << std::endl;
    }

    // Close the file
    input.close();

    return 0;
}

std::string readCurrentHashPassword(std::string filename)
{

    // Open input file for reading
    std::ifstream file(filename);

    // Find the line with the password in the file
    std::string line;
    while (std::getline(file, line))
    {
        if (line.find("Password:") != std::string::npos)
        {
            // Extract the password from the line
            std::string password = line.substr(line.find(":") + 2);

            return password;
        }
    }

    // Password not found
    std::cout << "Password not found.";
    return "";
}
