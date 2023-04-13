#include "../headers/read.h"
#include "../headers/write.h"
#include "../headers/users.h"

int main(int argc, char *argv[])
{

    // Check to see if the arguments were correctly passed
    // if (argc != 2)
    // {
    //     std::cout << "Usage " << argv[0] << " <input_file>" << std::endl;
    //     return 1;
    // }

    // std::string filename = argv[1];

    // -----------------------------------

    // WriteOnFileTest(filename);
    // ReadFile(filename);

    std::string username;
    std::string content;
    std::string foldername = {"../user_database/"};

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Content: ";
    std::cin >> content;

    WriteOnFile(foldername + username, content);
    ReadFile(foldername + username);

    // ----------------------------------

    // User usr("John", 30);
    // std::cout << usr.GetName() << usr.GetAge() << usr.GetRole() << std::endl;

    // Admin adm("Sahra", 15);
    // std::cout << adm.GetName() << adm.GetAge() << adm.GetRole() << std::endl;

    // usr.name = "Any";
    // adm.name = "Lilly";

    // usr.role = "Adm";

    // std::cout << usr.GetName() << usr.GetAge() << usr.GetRole() << std::endl;
    // std::cout << adm.GetName() << adm.GetAge() << adm.GetRole() << std::endl;
    // return 0;
}