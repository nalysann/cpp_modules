#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(const std::string& name)
        : ClapTrap(100,
                   100,
                   120,
                   120,
                   1,
                   name,
                   "SUP3R-TP",
                   60,
                   20,
                   5)
        , FragTrap(name)
        , NinjaTrap(name) {
    std::cout << "SUP3R-TP " << _name << " says "
              << "\"Supa kicka!\"." << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& other)
        : ClapTrap(other)
        , FragTrap(other)
        , NinjaTrap(other) {
    std::cout << "SUP3R-TP " << _name << " says "
              << "\"We call him Bruce U!\"." << std::endl;
}

SuperTrap& SuperTrap::operator=(const SuperTrap& other) {
    _hp = other._hp;
    _maxHp = other._maxHp;
    _ep = other._ep;
    _maxEp = other._maxEp;
    _level = other._level;
    _name = other._name;
    _type = other._type;
    _meleeDamage = other._meleeDamage;
    _rangeDamage = other._rangeDamage;
    _damageReduction = other._damageReduction;

    std::cout << "SUP3R-TP " << _name << " says "
              << "\"Why are you running?\"." << std::endl;

    return *this;
}

SuperTrap::~SuperTrap() {
    std::cout << "SUP3R-TP " << _name << " yells "
              << "\"Don't eat da poo-poo!\" and leaves." << std::endl;
}
