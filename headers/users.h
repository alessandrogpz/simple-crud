#pragma once

#include <iostream>
#include <fstream>
#include <string>

class User
{
public:
    // Constructor
    User(std::string username, std::string hashPassword, std::string firstName, std::string lastName, int age, std::string eMail, std::string role = "User");

    std::string GetUsername();
    std::string GetName();
    int GetAge();
    std::string GetRole();
    std::string GetPassword();

private:
    std::string username;
    std::string hashPassword;
    std::string firstName;
    std::string lastName;
    int age;
    std::string eMail;
    std::string role;

protected:
    // Setters
    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetAge(int age);
    void SetEMail(std::string eMail);
    void SetRole(std::string role);
};

class Admin : public User
{
public:
    // Constructor
    Admin(std::string firstName, int age);

private:
    void SetRole(std::string role);
};
