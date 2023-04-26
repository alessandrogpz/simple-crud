#pragma once

#include <iostream>
#include <fstream>
#include <string>

int CreateUserFile(std::string filename, std::string content);
int AppendOnFile(std::string filename, std::string content);