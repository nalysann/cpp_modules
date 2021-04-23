#include <iostream>

#include "AWeapon.hpp"
#include "PowerFist.hpp"

PowerFist::PowerFist()
        : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(const PowerFist& other)
        : AWeapon(other) {}

PowerFist& PowerFist::operator=(const PowerFist& other) {
    _name = other._name;
    _ap_cost = other._ap_cost;
    _damage = other._damage;

    return *this;
}

PowerFist::~PowerFist() {}

void PowerFist::attack() const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
