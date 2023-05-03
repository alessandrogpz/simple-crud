#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int ReadFile(std::string filename);
void readContent(std::string filename, std::string username);
std::string readCurrentHashPassword(std::string filename);