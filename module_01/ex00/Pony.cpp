#include <iostream>
#include <string>

#include "Pony.hpp"

Pony::Pony(const std::string &name)
    : _name(name) {
    ++_pony_population;
    std::cout << _name << " has joined the server." << std::endl;
}

Pony::~Pony() {
    --_pony_population;
    std::cout << _name << " has left the server." << std::endl;
}

void Pony::print_pony_population() {
    std::cout << "There are currently " << _pony_population
              << " ponies on the server." << std::endl;
}

void Pony::make_magic() const {
    std::cout << _name << " casts a random friendly spell on you!" << std::endl;
}

size_t Pony::_pony_population = 0;

void ponyOnTheStack(const std::string& name) {
    Pony pony(name);
    pony.make_magic();
}

void ponyOnTheHeap(const std::string& name) {
    Pony* pony = new Pony(name);
    pony->make_magic();
    delete pony;
}
