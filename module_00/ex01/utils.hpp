#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "Contact.hpp"

bool is_integer(const std::string& s);
void print_field(size_t n);
void print_field(const std::string& s, bool is_last);
void print_header();
void print_line(size_t index, const Contact& contact);

#endif
