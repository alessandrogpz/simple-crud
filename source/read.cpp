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

    // Ready to read file
    std::cout << "Loading file ..." << std::endl;
    std::cout << "Reading file: '" + filename + "'" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    // Read input from file
    std::string line;
    while (getline(input, line))
    {
        // Process input
        std::cout << line << std::endl;
    }

    // End of file
    std::cout << "---------------------------------------" << std::endl;

    // Close the file
    input.close();

    return 0;
}

void readContent(const std::string filename, const std::string username)
{
    /*
    This code reads the user file line by line and checks for the line containing "Content:".
    Once it finds that line, it sets a flag to true, indicating that it should start reading content lines.
    For each content line, it adds the line to a vector of strings.
    Once it has finished reading the file, it prints out the content lines.
    */

    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    // Ready to read file
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Loading file ..." << std::endl;
    std::cout << "Reading file: '" + username + "'" << std::endl;
    std::cout << "---------------- Content --------------" << std::endl;

    std::string line;
    bool foundContent = false;
    std::vector<std::string> contentLines;

    while (std::getline(file, line))
    {
        if (foundContent)
        {
            // Add content lines to vector
            contentLines.push_back(line);
        }
        else if (line.find("Content:") != std::string::npos)
        {
            foundContent = true;
        }
    }

    // Print content lines
    for (const auto &contentLine : contentLines)
    {
        std::cout << contentLine << std::endl;
    }
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
