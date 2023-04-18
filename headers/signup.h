#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <regex>

extern int age;
extern std::string firstName;
extern std::string lastName;
extern std::string eMail;

void getUserInfo();
int getValidInt(std::string prompt);
std::string getValidStringLettersOnly(std::string prompt);
bool isValidEmail(const std::string &email);
std::string getValidEmail(std::string prompt);