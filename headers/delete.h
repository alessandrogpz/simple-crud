#pragma once

#include <iostream>
#include <string>
#include <fstream>

bool deleteUserContentFile(const std::string &username);
bool deleteUserAccountAndUserContentFile(const std::string username);