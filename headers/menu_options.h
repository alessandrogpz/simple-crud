#pragma once

#include <iostream>
#include "state_machine.h"

Event logInOrSignUp();
void invalidInput();
Event writeReadOrDelete(std::string username);
void exitProgram();