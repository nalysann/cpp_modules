#include <iostream>
#include <string>

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon)
        : _name(name)
        , _weapon(weapon) {}

void HumanA::attack() const {
    std::cout << _name << " attacks with his "
              << _weapon.getType() << std::endl;
}
