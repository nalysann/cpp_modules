#include <cctype>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

#include "AddressBook.hpp"
#include "Contact.hpp"

bool is_integer(const std::string& s) {
    if (s.empty() || !isdigit(s[0]) || (s.size() > 1 && s[0] == '0')) {
        return false;
    }

    char* endptr;
    strtol(s.c_str(), &endptr, 10);

    return (*endptr == '\0');
}

void print_field(size_t n) {
    std::cout << std::setw(AddressBook::COLUMN_WIDTH)
              << n
              << AddressBook::COLUMN_SEP;
}

void print_field(const std::string& s, bool is_last) {
    if (static_cast<int>(s.size()) <= AddressBook::COLUMN_WIDTH) {
        std::cout << std::setw(AddressBook::COLUMN_WIDTH) << s;
    } else {
        std::cout << std::setw(AddressBook::COLUMN_WIDTH - 1) << s << '.';
    }
    if (!is_last) {
        std::cout << AddressBook::COLUMN_SEP;
    } else {
        std::cout << std::endl;
    }
}

void print_header() {
    print_field("Index", false);
    print_field("First name", false);
    print_field("Last name", false);
    print_field("Nickname", true);
}

void print_line(size_t index, const Contact& contact) {
    print_field(index);
    print_field(contact.first_name, false);
    print_field(contact.last_name, false);
    print_field(contact.nickname, true);
}