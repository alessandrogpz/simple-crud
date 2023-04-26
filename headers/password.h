#pragma once

#include <openssl/sha.h>
#include <iostream>
#include <string>

std::string setPassword();
std::string hashPassword(const std::string &password);