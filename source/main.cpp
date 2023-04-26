#include "../headers/login.h"
#include "../headers/signup.h"
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

    int mainMenuOption = logInOrSignUp();

    if (mainMenuOption == 1)
    {
        UserLogIn();
    }
    else if (mainMenuOption == 2)
    {
        UserSignUp();
    };

    return 0;
}