#include <iostream>
#include <string>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
        : _hp(100)
        , _maxHp(100)
        , _ep(100)
        , _maxEp(100)
        , _level(1)
        , _name(name)
        , _type("CL4P-TP")
        , _meleeDamage(10)
        , _rangeDamage(5)
        , _damageReduction(1) {
    std::cout << "CL4P-TP " << _name << " says "
              << "\"Booting completed\"." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
        : _hp(other._hp)
        , _maxHp(other._maxHp)
        , _ep(other._ep)
        , _maxEp(other._maxEp)
        , _level(other._level)
        , _name(other._name)
        , _type(other._type)
        , _meleeDamage(other._meleeDamage)
        , _rangeDamage(other._rangeDamage)
        , _damageReduction(other._damageReduction) {
    std::cout << "CL4P-TP " << _name << " says "
              << "\"Once again!\"." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
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

    std::cout << "CL4P-TP " << _name << " says "
              << "\"One more time!\"." << std::endl;

    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "CL4P-TP " << _name << " states "
              << "\"I'm done with this world!\" and runs away." << std::endl;
}

void ClapTrap::meleeAttack(const std::string& target) const {
    std::cout << _type << ' ' << _name << " attacks " << target << " in melee, causing "
              << _meleeDamage << " points of damage!" << std::endl;
}

void ClapTrap::rangedAttack(const std::string& target) const {
    std::cout << _type << ' ' << _name << " attacks " << target << " at range, causing "
              << _rangeDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned amount) {
    std::cout << _type << ' ' << _name << " is under attack!" << std::endl;

    if (_hp == 0) {
        std::cout << _type << ' ' << _name << " begs to spare him: "
                  << "\"I'm already dead, leave me alone!\"." << std::endl;
        return;
    }

    if (amount <= _damageReduction) {
        std::cout << _type << ' ' << _name << " says "
                  << "\"You bother me with that? L000SER!\"." << std::endl;
        return;
    }

    amount -= _damageReduction;

    if (_hp <= amount) {
        _hp = 0;
        std::cout << _type << ' ' << _name << " shouts "
                  << "\"I'm too pretty to die!\" and dies." << std::endl;
    } else {
        _hp -= amount;
        std::cout << "Extra ouch! " << _type << ' ' << _name
                  << " has " << _hp << " HP left." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned amount) {
    std::cout << _type << ' ' << _name << " spots health and says "
              << "\"Sweet life juice!\"." << std::endl;

    if (_maxHp - _hp <= amount) {
        _hp = _maxHp;
        std::cout << _type << ' ' << _name << " is at max HP!" << std::endl;
    } else {
        _hp += amount;
        std::cout << _type << ' ' << _name << " now has " << _hp << " HP!" << std::endl;
    }
}

ClapTrap::ClapTrap(unsigned hp,
                   unsigned maxHp,
                   unsigned ep,
                   unsigned maxEp,
                   unsigned level,
                   const std::string& name,
                   const std::string& type,
                   unsigned meleeDamage,
                   unsigned rangeDamage,
                   unsigned damageReduction)
        : _hp(hp)
        , _maxHp(maxHp)
        , _ep(ep)
        , _maxEp(maxEp)
        , _level(level)
        , _name(name)
        , _type(type)
        , _meleeDamage(meleeDamage)
        , _rangeDamage(rangeDamage)
        , _damageReduction(damageReduction) {
    std::cout << "CL4P-TP " << _name << " says "
              << "\"Job's done\"." << std::endl;
}
