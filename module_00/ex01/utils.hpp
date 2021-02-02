#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

#include "Contact.hpp"

bool isInteger(const std::string& s);
void printHeader(std::ostream& os);
void printLine(std::ostream& os, size_t index, const Contact& contact);

#endif
