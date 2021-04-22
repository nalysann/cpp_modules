#include <iostream>
#include <string>

#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer(const std::string& name, const std::string& title)
        : _name(name)
        , _title(title) {
    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& other)
        : _name(other._name)
        , _title(other._title) {
    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer& Sorcerer::operator=(const Sorcerer& other) {
    _name = other._name;
    _title = other._title;

    std::cout << _name << ", " << _title << ", is born!" << std::endl;

    return *this;
}

Sorcerer::~Sorcerer() {
    std::cout << _name << ", " << _title << ", is dead. "
              << "Consequences will never be the same!" << std::endl;
}

const std::string& Sorcerer::getName() const {
    return _name;
}

const std::string& Sorcerer::getTitle() const {
    return _title;
}

void Sorcerer::polymorph(const Victim& victim) const {
    victim.getPolymorphed();
}

std::ostream& operator<<(std::ostream& os, const Sorcerer& sorcerer) {
    return os << "I am " << sorcerer.getName() << ", "
              << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
}
