#include "../headers/users.h"
#include "../headers/write.h"
#include "../headers/user_data.h"
#include "../headers/login.h"

// Constructor definition for User
User::User(std::string username, std::string hashPassword, std::string firstName, std::string lastName, int age, std::string eMail, std::string role)
{
    this->username = username;
    this->hashPassword = hashPassword;
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
    this->eMail = eMail;
    this->role = role;

    // Write user information to file
    std::string content_filename = username + ".txt";

    createUserContentFile(users_content_folder + content_filename);
    addNewUserToDB(username, password, GetName(), age, eMail, role, content_filename);

    loggedIn = true;
}

// Destructor
User::~User()
{
}

// Getters -----------------------------------------
std::string User::GetUsername()
{
    return username;
}

std::string User::GetPassword()
{
    return hashPassword;
}

std::string User::GetName()
{
    return firstName + " " + lastName;
}

int User::GetAge()
{
    return age;
}

std::string User::GetRole()
{
    return role;
}

// Setters -----------------------------------------
void User::SetFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void User::SetLastName(std::string lastName)
{
    this->lastName = lastName;
}

void User::SetAge(int age)
{
    this->age = age;
}

void User::SetEMail(std::string eMail)
{
    this->eMail = eMail;
}

void User::SetRole(std::string role)
{
    this->role = role;
}

// Constructor definition for Admin
Admin::Admin(std::string firstName, int age) : User("", "", firstName, "", age, "", "")
{
    SetRole("Admin");
}

void Admin::SetRole(std::string role)
{
    User::SetRole(role);
}
