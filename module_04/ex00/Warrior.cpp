#include <iostream>
#include <string>

#include "Warrior.hpp"

Warrior::Warrior(const std::string& name)
        : Victim(name) {
    std::cout << "Lok'tar Ogar." << std::endl;
}

Warrior::Warrior(const Warrior& other)
        : Victim(other) {
    std::cout << "Lok'tar Ogar." << std::endl;
}

Warrior& Warrior::operator=(const Warrior& other) {
    _name = other._name;

    std::cout << "Lok'tar Ogar." << std::endl;

    return *this;
}

Warrior::~Warrior() {
    std::cout << "Dabu..." << std::endl;
}

void Warrior::getPolymorphed() const {
    std::cout << _name << " has been turned into a chicken!" << std::endl;
}
