#ifndef ADDRESSBOOK_HPP
#define ADDRESSBOOK_HPP

#include <iostream>

#include "Contact.hpp"

class AddressBook {
  public:
    AddressBook();

    void add(const Contact& contact);
    const Contact& getContact(size_t index) const;
    size_t getSize() const;
    size_t getSizeNonEmpty() const;
    void search(std::string& input) const;

    static const int COLUMN_WIDTH = 10;
    static const char COLUMN_SEP = '|';

  private:
    static const size_t _MAX_SIZE = 8;

    Contact _contacts[_MAX_SIZE];
    size_t _size;
    size_t _sizeNonEmpty;
};

std::ostream& operator<<(std::ostream& os, const AddressBook& address_book);

#endif
