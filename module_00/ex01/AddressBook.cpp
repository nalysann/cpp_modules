#include <cstdlib>
#include <iostream>

#include "AddressBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

AddressBook::AddressBook()
    : _size(0)
    , _sizeNonEmpty(0)
{}

void AddressBook::add(const Contact& contact) {
    if (_size >= _MAX_SIZE) {
        std::cout << "Address book is full, enter a number from 1 to "
                  << _MAX_SIZE << " to overwrite the" << std::endl
                  << "existing contact or anything else to abort the current operation: ";

        std::string input;
        getline(std::cin, input);

        if (isInteger(input)) {
            size_t index = strtol(input.c_str(), NULL, 10);
            if (1 <= index && index <= _MAX_SIZE) {
                if (!_contacts[index - 1].isEmpty()) {
                    --_sizeNonEmpty;
                }
                if (!contact.isEmpty()) {
                    ++_sizeNonEmpty;
                }
                _contacts[index - 1] = contact;
            }
        }
    } else {
        if (!contact.isEmpty()) {
            ++_sizeNonEmpty;
        }
        _contacts[_size++] = contact;
    }
}

const Contact& AddressBook::getContact(size_t index) const {
    return _contacts[index];
}

size_t AddressBook::getSize() const {
    return _size;
}

size_t AddressBook::getSizeNonEmpty() const {
    return _sizeNonEmpty;
}

void AddressBook::search(std::string& input) const {
    while (true) {
        if (isInteger(input)) {
            size_t index = strtol(input.c_str(), NULL, 10);
            if (1 <= index && index <= getSize()) {
                const Contact &contact = getContact(index - 1);
                if (!contact.isEmpty()) {
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
    if (address_book.getSizeNonEmpty() > 0) {
        printHeader(os);
        for (size_t i = 0; i < address_book.getSize(); ++i) {
            const Contact& contact = address_book.getContact(i);
            if (!contact.isEmpty()) {
                printLine(os, i + 1, contact);
            }
        }
    } else {
        os << "There are no non-empty contacts in the address book!" << std::endl;
    }
    return os;
}