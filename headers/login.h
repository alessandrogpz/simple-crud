#pragma once

#include <iostream>
#include <fstream>

extern std::string username;
extern std::string foldername;

bool CheckIfUserExists(const std::string &filename);
void UserLogIn();