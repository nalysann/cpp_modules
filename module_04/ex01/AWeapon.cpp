#include <string>

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string& name, int ap_cost, int damage)
        : _name(name)
        , _ap_cost(ap_cost)
        , _damage(damage) {}

AWeapon::AWeapon(const AWeapon& other)
        : _name(other._name)
        , _ap_cost(other._ap_cost)
        , _damage(other._damage) {}

AWeapon& AWeapon::operator=(const AWeapon& other) {
    _name = other._name;
    _ap_cost = other._ap_cost;
    _damage = other._damage;

    return *this;
}

AWeapon::~AWeapon() {}

const std::string& AWeapon::getName() const {
    return _name;
}

int AWeapon::getAPCost() const {
    return _ap_cost;
}

int AWeapon::getDamage() const {
    return _damage;
}
