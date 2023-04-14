#pragma once

#include <iostream>
#include <fstream>
#include <string>

int WriteOnFileTest(std::string filename);
int CreateUserFile(std::string filename, std::string content);
int AppendOnFile(std::string filename, std::string content);