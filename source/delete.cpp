#include "../headers/delete.h"

bool deleteFile(const std::string filename, const std::string username)
{
    std::cout << "Are you sure you want to delete " << username << "? (y/n) ";
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'y' || confirmation == 'Y')
    {
        if (std::remove(filename.c_str()) != 0)
        {
            std::cout << "Error deleting file" << std::endl;
            return false;
        }
        else
        {
            std::cout << "File successfully deleted" << std::endl;
            return true;
        }
    }
    else
    {
        std::cout << "File deletion cancelled" << std::endl;
        return false;
    }
}
