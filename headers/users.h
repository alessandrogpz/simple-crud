#include <iostream>
#include <fstream>
#include <string>

class User
{
public:
    // Constructor
    std::string name;
    int age;
    std::string role;

    User(std::string name, int age, std::string role = "User")
    {
        this->name = name;
        this->age = age;
        this->role = role;
    }

    std::string GetName()
    {
        return name;
    }

    int GetAge()
    {
        return age;
    }

    std::string GetRole()
    {
        return role;
    }

private:
    std::string GetRole() const
    {
        return role;
    }

protected:
    // Getters and Setters
    void SetName(std::string name)
    {
        this->name = name;
    }

    void SetAge(int age)
    {
        this->age = age;
    }

    void SetRole(std::string role)
    {
        this->role = role;
    }
};

class Admin : public User
{

public:
    // Constructor
    Admin(std::string name, int age) : User(name, age, "")
    {
        SetRole("Admin");
    }

private:
    void SetRole(std::string role)
    {
        User::SetRole(role);
    }
};