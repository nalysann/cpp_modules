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

void print_field(std::ostream& os, size_t n) {
    os << std::setw(AddressBook::COLUMN_WIDTH)
       << n
       << AddressBook::COLUMN_SEP;
}

void print_field(std::ostream& os, const std::string& s, bool is_last) {
    if (static_cast<int>(s.size()) <= AddressBook::COLUMN_WIDTH) {
        os << std::setw(AddressBook::COLUMN_WIDTH) << s;
    } else {
        os << std::setw(AddressBook::COLUMN_WIDTH - 1) << s << '.';
    }
    if (!is_last) {
        os << AddressBook::COLUMN_SEP;
    } else {
        os << std::endl;
    }
}

void print_header(std::ostream& os) {
    print_field(os, "Index", false);
    print_field(os, "First name", false);
    print_field(os, "Last name", false);
    print_field(os, "Nickname", true);
}

void print_line(std::ostream& os, size_t index, const Contact& contact) {
    print_field(os, index);
    print_field(os, contact.get_first_name(), false);
    print_field(os, contact.get_last_name(), false);
    print_field(os, contact.get_nickname(), true);
}