#include <iostream>

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
        : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(const PlasmaRifle& other)
        : AWeapon(other) {}

PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle& other) {
    _name = other._name;
    _ap_cost = other._ap_cost;
    _damage = other._damage;

    return *this;
}

PlasmaRifle::~PlasmaRifle() {}

void PlasmaRifle::attack() const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
