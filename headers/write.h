#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sqlite3.h>

int createUserFile(std::string filename, std::string content);
int appendOnFile(std::string filename);
void addUser(const std::string &username, const std::string &password, const std::string &name, int age, const std::string &email, const std::string &role, const std::string &contentLink);