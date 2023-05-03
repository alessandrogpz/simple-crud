#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

void getUserInfo();
extern std::string firstName;
extern std::string lastName;
extern int age;
extern std::string eMail;

bool UserSignUp();
extern std::string foldername;
extern std::string username;
extern std::string password;
extern std::string createAccount;
extern std::string username;

int getValidInt(std::string prompt);
std::string getValidStringLettersOnly(std::string prompt);
bool isValidEmail(const std::string &email);
std::string getValidEmail(std::string prompt);
