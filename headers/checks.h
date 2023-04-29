#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <regex>

bool CheckIfUserExists(const std::string &filename);
bool isValidEmail(const std::string &email);
bool passwordAuthenticate(const std::string &password);