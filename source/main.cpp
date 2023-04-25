#include "../headers/login.h"
#include "../headers/password.h"
#include "../headers/login_or_signup.h"

int main(/*int argc, char *argv[]*/)
{

    // Check to see if the arguments were correctly passed
    // if (argc != 2)
    // {
    //     std::cout << "Usage " << argv[0] << " <input_file>" << std::endl;
    //     return 1;
    // }

    // std::string filename = argv[1];

    // -----------------------------------

    // std::cout << "Content: ";
    // std::cin >> content;

    int mainMenuOption = logInOrSignUp();

    if (mainMenuOption == 1)
    {
        UserLogIn();
    }
    else if (mainMenuOption == 2)
    {
        // SignUp()
    };
    //  option menu

    // WriteOnFile(foldername + username, content);
    // ReadFile(foldername + username);

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