#include "../headers/login.h"
#include "../headers/signup.h"
#include "../headers/password.h"
#include "../headers/menu_options.h"
#include "../headers/read.h"
#include "../headers/write.h"
#include "../headers/state_machine.h"
#include "../headers/delete.h"

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

    // Implement the state machine
    State state = State::MainMenu;
    while (true)
    {
        switch (state)
        {
        case State::MainMenu:
        {
            Event event = logInOrSignUp();
            if (event == Event::LOGIN)
            {
                state = State::Login;
            }
            else if (event == Event::SIGNUP)
            {
                state = State::SignUp;
            }
            else if (event == Event::EXIT)
            {
                exitProgram();
            }
            else
            {
                // Handle invalid input
                invalidInput();
            }
            break;
        }
        case State::Login:
        {
            if (UserLogIn())
            {
                state = State::ReadWriteDelete;
            }
            else
            {
                state = State::MainMenu;
            }
            break;
        }
        case State::ReadWriteDelete:
        {
            Event event = writeReadOrDelete(username);

            if (event == Event::WRITE)
            {
                appendOnFile(users_content_folder + username + ".txt");
            }
            else if (event == Event::READ)
            {
                readUserContentFile(username);
            }
            else if (event == Event::DELETE_FILES)
            {
                (deleteUserContentFile(username));
            }
            else if (event == Event::DELETE_USER)
            {
                if (deleteUserAccountAndUserContentFile(username))
                {
                    state = State::MainMenu;
                };
            }
            else if (event == Event::LOGOUT)
            {
                state = State::MainMenu;
            }
            else
            {
                // Handle invalid input
                invalidInput();
            }
            break;
        }
        case State::SignUp:
        {
            if (UserSignUp())
            {
                state = State::ReadWriteDelete;
            }
            else
            {
                state = State::MainMenu;
            }
            break;
        }
        }
    }
    return 0;
}