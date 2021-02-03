#include <iostream>
#include <string>

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string& name)
    : _name(name)
    , _weapon(NULL) {}

void HumanB::setWeapon(const Weapon& weapon) {
    _weapon = &weapon;
}

void HumanB::attack() const {
    std::cout << _name << " attacks with his "
              << _weapon->getType() << std::endl;
}
