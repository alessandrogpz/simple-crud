#include "read.h"

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
