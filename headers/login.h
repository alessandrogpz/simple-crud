#pragma once

#include <iostream>
#include <fstream>

bool CheckIfUserExists(const std::string &filename);

bool UserLogIn();
extern std::string username;
extern std::string filename;
extern std::string password;
extern std::string foldername;
extern std::string filename;