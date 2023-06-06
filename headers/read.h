#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sqlite3.h>

int readUserContentFile(const std::string &username);
std::string readUserHashPassword(const std::string &username);