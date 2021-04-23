#include <iostream>

#include "AlienAtomizer.hpp"
#include "AWeapon.hpp"

AlienAtomizer::AlienAtomizer()
        : AWeapon("Alien Atomizer", 10, 35) {}

AlienAtomizer::AlienAtomizer(const AlienAtomizer& other)
        : AWeapon(other) {}

AlienAtomizer& AlienAtomizer::operator=(const AlienAtomizer& other) {
    _name = other._name;
    _ap_cost = other._ap_cost;
    _damage = other._damage;

    return *this;
}

AlienAtomizer::~AlienAtomizer() {}

void AlienAtomizer::attack() const {
    std::cout << "* powww powww powww *" << std::endl;
}
