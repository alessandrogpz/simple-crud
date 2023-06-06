#pragma once

#include <iostream>
#include <string>

bool deleteUserContentFile(const std::string &username);
bool deleteUserAccountAndUserContentFile(const std::string username);