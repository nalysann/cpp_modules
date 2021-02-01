#include <string>

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
    : _type(type) {}

const std::string& Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string& type) {
    _type = type;
}
