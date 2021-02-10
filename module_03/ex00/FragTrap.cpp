#include <cstdlib>
#include <ctime>
#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
    : _hp(100)
    , _ep(100)
    , _level(1)
    , _name(name) {
    std::cout << "FR4G_TP " << _name << " says "
              << "\"Let's get this party started!\"." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : _hp(other._hp)
    , _ep(other._ep)
    , _level(other._level)
    , _name(other._name) {
    std::cout << "FR4G_TP " << _name << " says "
              << "\"Recompiling my combat code!\"." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    _hp = other._hp;
    _ep = other._ep;
    _level = other._level;
    _name = other._name;

    std::cout << "FR4G_TP " << _name << " says "
              << "\"This time it'll be awesome, I promise!\"." << std::endl;

    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FR4G_TP " << _name << " yells "
              << "\"I'll get you next time!\" and leaves." << std::endl;
}

void FragTrap::meleeAttack(const std::string& target) const {
    std::cout << "FR4G-TP " << _name << " attacks " << target << " in melee, causing "
              << _meleeDamage << " points of damage!" << std::endl;
}
void FragTrap::rangedAttack(const std::string& target) const {
    std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing "
              << _rangeDamage << " points of damage!" << std::endl;
}
void FragTrap::takeDamage(unsigned amount) {
    std::cout << "FR4G-TP " << _name << " is under attack!" << std::endl;

    if (_hp == 0) {
        std::cout << "FR4G-TP " << _name << " begs to spare him: "
                  << "\"I'm already dead, leave me alone!\"." << std::endl;
        return;
    }

    if (amount <= _damageReduction) {
        std::cout << "FR4G-TP " << _name << " says "
                  << "\"You bother me with that? L000SER!\"." << std::endl;
        return;
    }

    amount -= _damageReduction;

    if (_hp <= amount) {
        _hp = 0;
        std::cout << "FR4G-TP " << _name << " shouts "
                  << "\"I'm too pretty to die!\" and dies." << std::endl;
    } else {
        _hp -= amount;
        std::cout << "Extra ouch! " << "FR4G-TP " << _name
                  << " has " << _hp << " HP left." << std::endl;
    }
}

void FragTrap::beRepaired(unsigned amount) {
    std::cout << "FR4G-TP " << _name << " spots health and says "
              << "\"Sweet life juice!\"." << std::endl;

    _hp += amount;

    if (_hp >= _maxHp) {
        _hp = _maxHp;
        std::cout << "FR4G-TP " << _name << " is at max HP!" << std::endl;
    } else {
        std::cout << "FR4G-TP " << _name << " now has " << _hp << " HP!" << std::endl;
    }
}

void FragTrap::vaulthunter_dot_exe(const std::string& target) {
    if (_ep < _vhExeEp) {
        std::cout << "FR4G-TP " << _name << " says "
                  << "\"You need to construct additional pylons"
                  << "...sorry, wrong game!\"." << std::endl;
        return;
    }

    _ep -= _vhExeEp;

    static const size_t num_choices = 6;
    const size_t choice = rand() % num_choices;

    switch (choice) {
        case 0:
            std::cout << "FR4G-TP " << _name <<  " becomes a gun wizard!" << std::endl;
            rangedAttack(target);
            break;
        case 1:
            std::cout << "FR4G-TP " << _name << " transforms into a pirate ship!" << std::endl;
            rangedAttack(target);
            break;
        case 2:
            std::cout << "FR4G-TP " << _name << " transforms into a meat unicycle!" << std::endl;
            meleeAttack(target);
            break;
        case 3:
            std::cout << "FR4G-TP " << _name << " unleashes the laser inferno! " << std::endl;
            meleeAttack(target);
            break;
        case 4:
            std::cout << "FR4G-TP " << _name << " starts the torgue fiesta!" << std::endl;
            rangedAttack(target);
            break;
        case 5:
            std::cout << "FR4G-TP " << _name << " turns invisible and starts lurking..." << std::endl;
            meleeAttack(target);
            break;
        default:
            break;
    }
}
