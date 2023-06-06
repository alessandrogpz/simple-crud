#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <sqlite3.h>

bool CheckIfUserExists(const std::string &username);
bool isValidEmail(const std::string &email);
bool passwordAuthenticate(const std::string &password);