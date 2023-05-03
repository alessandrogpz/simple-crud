#include "../headers/write.h"

int createUserFile(std::string filename, std::string content)
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

int appendOnFile(std::string filename)
{
    /*
    This is a function that appends user input to a file.
    It opens the file for writing (appending), and if the file is not opened successfully, it displays an error message and returns 1.
    The function then loops until the user enters three consecutive empty lines, indicating that they have finished entering text.
    It reads user input from the console and appends it to a string called "content".
    If the user enters an empty line, the function increments a counter of empty lines.
    If the user enters a non-empty line, the function adds the line to the "content" string and resets the counter of empty lines.
    Finally, the function writes the "content" string to the file and returns 0.
    */

    // Open input file for writing (appending)
    std::ofstream outfile(filename, std::ios::app);

    // Check if the file was opened successfully
    if (!outfile.is_open())
    {
        std::cout << "Error opening file " << filename << " for appending " << std::endl;
        return 1;
    }

    std::string content;

    // loop until three consecutive empty lines are entered
    int empty_lines = 0;
    while (empty_lines < 2)
    {
        std::string line;
        std::getline(std::cin, line);

        // check if the line is empty
        if (line.empty())
        {
            empty_lines++;
            content += "\n";
        }
        else
        {
            // add the line to the content string
            content += line + "\n";
            empty_lines = 0; // reset the count of empty lines
        }
    }

    // write the content to the file
    outfile << content;

    // Close input file
    outfile.close();
    return 0;
}
