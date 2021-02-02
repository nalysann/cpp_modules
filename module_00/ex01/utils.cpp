#include <cctype>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

#include "AddressBook.hpp"
#include "Contact.hpp"

bool isInteger(const std::string& s) {
    if (s.empty() || !isdigit(s[0]) || (s.size() > 1 && s[0] == '0')) {
        return false;
    }

    char* endptr;
    strtol(s.c_str(), &endptr, 10);

    return (*endptr == '\0');
}

static void printField(std::ostream& os, size_t n) {
    os << std::setw(AddressBook::COLUMN_WIDTH)
       << n
       << AddressBook::COLUMN_SEP;
}

static void printField(std::ostream& os, const std::string& s, bool is_last) {
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

void printHeader(std::ostream& os) {
    printField(os, "Index", false);
    printField(os, "First name", false);
    printField(os, "Last name", false);
    printField(os, "Nickname", true);
}

void printLine(std::ostream& os, size_t index, const Contact& contact) {
    printField(os, index);
    printField(os, contact.getFirstName(), false);
    printField(os, contact.getLastName(), false);
    printField(os, contact.getNickname(), true);
}