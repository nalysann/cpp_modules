#include <iostream>
#include <string>

#include "Peon.hpp"

Peon::Peon(const std::string& name)
        : Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon& other)
        : Victim(other) {
    std::cout << "Zog zog." << std::endl;
}

Peon& Peon::operator=(const Peon& other) {
    _name = other._name;

    std::cout << "Zog zog." << std::endl;

    return *this;
}

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const {
    std::cout << _name << " has been turned into a pink pony!" << std::endl;
}
