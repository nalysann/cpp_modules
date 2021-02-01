#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

#include "Contact.hpp"

bool is_integer(const std::string& s);
void print_field(std::ostream& os, size_t n);
void print_field(std::ostream& os, const std::string& s, bool is_last);
void print_header(std::ostream& os);
void print_line(std::ostream& os, size_t index, const Contact& contact);

#endif
