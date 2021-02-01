#include <cstdlib>
#include <iostream>

#include "AddressBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

AddressBook::AddressBook()
    : _size(0)
    , _size_non_empty(0)
{}

void AddressBook::add(const Contact& contact) {
    if (_size >= _MAX_SIZE) {
        std::cout << "Address book is full, enter a number from 1 to "
                  << _MAX_SIZE << " to overwrite the" << std::endl
                  << "existing contact or anything else to abort the current operation: ";

        std::string input;
        getline(std::cin, input);

        if (is_integer(input)) {
            size_t index = strtol(input.c_str(), NULL, 10);
            if (1 <= index && index <= _MAX_SIZE) {
                if (!_contacts[index - 1].is_empty()) {
                    --_size_non_empty;
                }
                if (!contact.is_empty()) {
                    ++_size_non_empty;
                }
                _contacts[index - 1] = contact;
            }
        }
    } else {
        if (!contact.is_empty()) {
            ++_size_non_empty;
        }
        _contacts[_size++] = contact;
    }
}

const Contact& AddressBook::get_contact(size_t index) const {
    return _contacts[index];
}

size_t AddressBook::get_size() const {
    return _size;
}

size_t AddressBook::get_size_non_empty() const {
    return _size_non_empty;
}

void AddressBook::search(std::string& input) const {
    while (true) {
        if (is_integer(input)) {
            size_t index = strtol(input.c_str(), NULL, 10);
            if (1 <= index && index <= get_size()) {
                const Contact &contact = get_contact(index - 1);
                if (!contact.is_empty()) {
                    std::cout << contact << std::endl;
                    break;
                }
            } else if (index == 0) {
                break;
            }
        }
        std::cout << "Invalid index, try again or enter 0 to abort the current operation: ";
        getline(std::cin, input);
    }
}

std::ostream& operator<<(std::ostream& os, const AddressBook& address_book) {
    if (address_book.get_size_non_empty() > 0) {
        print_header(os);
        for (size_t i = 0; i < address_book.get_size(); ++i) {
            const Contact& contact = address_book.get_contact(i);
            if (!contact.is_empty()) {
                print_line(os, i + 1, contact);
            }
        }
    } else {
        os << "There are no non-empty contacts in the address book!";
    }
    return os;
}