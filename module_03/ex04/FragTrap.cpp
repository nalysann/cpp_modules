#include <cstdlib>
#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
        : ClapTrap(100,
                   100,
                   100,
                   100,
                   1, name,
                   "FR4G-TP",
                   30,
                   20,
                   5) {
    std::cout << "FR4G-TP " << _name << " says "
              << "\"Let's get this party started!\"." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
        : ClapTrap(other) {
    std::cout << "FR4G-TP " << _name << " says "
              << "\"Recompiling my combat code!\"." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
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

    std::cout << "FR4G-TP " << _name << " says "
              << "\"This time it'll be awesome, I promise!\"." << std::endl;

    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FR4G-TP " << _name << " yells "
              << "\"I'll get you next time!\" and leaves." << std::endl;
}

void FragTrap::vaulthunter_dot_exe(const std::string& target) {
    static const unsigned _vhExeEp = 25;

    if (_ep < _vhExeEp) {
        std::cout << _type << ' ' << _name << " says "
                  << "\"You need to construct additional pylons"
                  << "...sorry, wrong game!\"." << std::endl;
        return;
    }

    _ep -= _vhExeEp;

    static const std::string package_names[] = {
            " becomes a gun wizard!",
            " transforms into a pirate ship!",
            " transforms into a meat unicycle!",
            " unleashes the laser inferno! ",
            " starts the torgue fiesta!",
            " turns invisible and starts lurking...",
    };

    static const FragTrap::_attack package_attacks[] = {
            &FragTrap::rangedAttack,
            &FragTrap::rangedAttack,
            &FragTrap::meleeAttack,
            &FragTrap::meleeAttack,
            &FragTrap::rangedAttack,
            &FragTrap::meleeAttack,
    };

    static const unsigned num_choices = 6;
    const size_t choice = rand() % num_choices;

    std::cout << _type << ' ' << _name << package_names[choice] << std::endl;
    (this->*package_attacks[choice])(target);
}