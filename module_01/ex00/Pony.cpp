#include <iostream>
#include <string>

#include "Pony.hpp"

Pony::Pony(const std::string& name)
        : _name(name) {
    ++_ponyPopulation;
    std::cout << _name << " has joined the server." << std::endl;
}

Pony::~Pony() {
    --_ponyPopulation;
    std::cout << _name << " has left the server." << std::endl;
}

void Pony::printPonyPopulation() {
    std::cout << "There are currently " << _ponyPopulation
              << " ponies on the server." << std::endl;
}

void Pony::makeMagic() const {
    std::cout << _name << " casts a random friendly spell on you!" << std::endl;
}

size_t Pony::_ponyPopulation = 0;

void ponyOnTheStack(const std::string& name) {
    Pony pony(name);
    pony.makeMagic();
}

void ponyOnTheHeap(const std::string& name) {
    Pony* pony = new Pony(name);
    pony->makeMagic();
    delete pony;
}
