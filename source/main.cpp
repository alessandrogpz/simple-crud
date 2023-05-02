#include "../headers/login.h"
#include "../headers/signup.h"
#include "../headers/password.h"
#include "../headers/menu_options.h"
#include "../headers/read.h"
#include "../headers/write.h"

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

    while (true)
    {
        int mainMenuOption = logInOrSignUp();

        if (mainMenuOption == 1)
        {
            UserLogIn();
            writeReadOrDelete();

            // append
            // content
            // append
            AppendOnFile(foldername + username + ".txt");
        }
        else if (mainMenuOption == 2)
        {
            UserSignUp();
        };
    }
    return 0;
}