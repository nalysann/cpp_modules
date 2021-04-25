#include <iostream>
#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"

NinjaTrap::NinjaTrap(const std::string& name)
        : ClapTrap(60,
                   60,
                   120,
                   120,
                   1,
                   name,
                   "N1NJ4-TP",
                   60,
                   5,
                   0) {
    std::cout << "N1NJ4-TP " << _name << " says "
              << "\"Everybody in Uganda knows kung-fu!\"." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& other)
        : ClapTrap(other) {
    std::cout << "N1NJ4-TP " << _name << " says "
              << "\"Action is coming...\"." << std::endl;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& other) {
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

    std::cout << "N1NJ4-TP " << _name << " says "
              << "\"I'm the invisible trap!\"." << std::endl;

    return *this;
}

NinjaTrap::~NinjaTrap() {
    std::cout << "N1NJ4-TP " << _name << " yells "
              << "\"Captain Alex is dead!\" and leaves." << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap& clap) const {
    std::cout << _type << ' ' << _name << " whispers "
              << "\"Look who we got here...\"." << std::endl;
    meleeAttack(clap.getType() + ' ' + clap.getName());
    clap.takeDamage(_meleeDamage);
}

void NinjaTrap::ninjaShoebox(FragTrap& frag) const {
    std::cout << _type << ' ' << _name << " whispers "
              << "\"Got you!\"." << std::endl;
    meleeAttack(frag.getType() + ' ' + frag.getName());
    frag.takeDamage(_meleeDamage);
}

void NinjaTrap::ninjaShoebox(NinjaTrap& ninja) const {
    std::cout << _type << ' ' << _name << " whispers "
              << "\"This is my mission, you idiot!\"." << std::endl;
    rangedAttack(ninja.getType() + ' ' + ninja.getName());
    ninja.takeDamage(_rangeDamage);
}

void NinjaTrap::ninjaShoebox(ScavTrap& scav) const {
    std::cout << _type << ' ' << _name << " whispers "
              << "\"Expect the unexpectable!\"." << std::endl;
    meleeAttack(scav.getType() + ' ' + scav.getName());
    scav.takeDamage(_meleeDamage);
}
