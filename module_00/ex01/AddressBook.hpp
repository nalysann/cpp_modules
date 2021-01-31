#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "Contact.hpp"

class AddressBook {
  public:
    AddressBook();

    void add(const Contact& contact);
    const Contact& get_contact(size_t index) const;
    size_t get_size() const;
    size_t get_size_non_empty() const;
    void search(std::string& input) const;

    static const int COLUMN_WIDTH = 10;
    static const char COLUMN_SEP = '|';

  private:
    static const size_t MAX_SIZE = 8;

    Contact contacts[MAX_SIZE];
    size_t size;
    size_t size_non_empty;
};

std::ostream& operator<<(std::ostream& os, const AddressBook& address_book);

#endif
