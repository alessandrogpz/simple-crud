#pragma once

// Define the states of the state machine
enum class State
{
    MainMenu,
    Login,
    ReadWriteDelete,
    SignUp
};

// Define the events that trigger state transitions
enum class Event
{
    LOGIN,
    SIGNUP,
    BACK,
    WRITE,
    READ,
    DELETE_FILES,
    DELETE_USER,
    LOGOUT,
    EXIT,
    INVALID
};