#include "../headers/write.h"

int WriteOnFileTest(std::string filename)
{
    // Open input file for writing
    std::ofstream outfile(filename);

    // Check if the file was opened successfully
    if (!outfile.is_open())
    {
        std::cout << "Error opening file for writing " << filename << std::endl;
        return 1;
    }

    // Write some data to the file
    outfile << "Hello, file!" << std::endl;

    // Close input file
    outfile.close();

    return 0;
}

int CreateUserFile(std::string filename, std::string content)
{

    // Open input file for writing (create a new file)
    std::ofstream outfile(filename);

    // Check if the file was opened successfully
    if (!outfile.is_open())
    {
        std::cout << "Error opening file " << filename << " for writing " << std::endl;
        return 1;
    }

    // Write on file
    outfile << content;

    // Close input file
    outfile.close();
    return 0;
}

int AppendOnFile(std::string filename, std::string content)
{
    // Open input file for writing (appending)
    std::ofstream outfile(filename, std::ios::app);

    // Check if the file was opened successfully
    if (!outfile.is_open())
    {
        std::cout << "Error opening file " << filename << " for appending " << std::endl;
        return 1;
    }

    // write on file
    outfile << content;

    // Close input file
    outfile.close();
    return 0;
}