#include <iostream>
#include <string>

#include "AddressBook.hpp"
#include "Contact.hpp"

int main() {
    AddressBook address_book;

    while (true) {
        std::string query;
        getline(std::cin, query);
        if (query == "ADD") {
            Contact new_contact;
            std::cin >> new_contact;
            address_book.add(new_contact);
        } else if (query == "SEARCH") {
            std::cout << address_book;
            if (address_book.get_size_non_empty() > 0) {
                std::string input;
                std::cout << "Enter the index of the desired contact "
                          << "or 0 to abort the current operation: ";
                getline(std::cin, input);
                address_book.search(input);
            }
        } else if (query == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. List of available commands:" << std::endl
                      << " - ADD" << std::endl
                      << " - SEARCH" << std::endl
                      << " - EXIT" << std::endl;
        }
    }
}