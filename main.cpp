#include "read.h"
#include "write.h"
#include "users.h"

int main(int argc, char *argv[])
{

    // Check to see if the arguments were correctly passed
    if (argc != 2)
    {
        std::cout << "Usage " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];

    // WriteOnFileTest(filename);
    // ReadFile(filename);

    WriteOnFile(filename, "This is a test\n");
    ReadFile(filename);

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