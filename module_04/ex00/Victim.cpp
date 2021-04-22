#include <iostream>
#include <string>

#include "Victim.hpp"

Victim::Victim(const std::string& name)
        : _name(name) {
    std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim& other)
        : _name(other._name) {
    std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim& Victim::operator=(const Victim& other) {
    _name = other._name;

    std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;

    return *this;
}

Victim::~Victim() {
    std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

const std::string& Victim::getName() const {
    return _name;
}

void Victim::getPolymorphed() const {
    std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Victim& victim) {
    return os << "I'm " << victim.getName() << " and I like otters!" << std::endl;
}
