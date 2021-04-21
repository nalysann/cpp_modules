#include <cstdlib>
#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
        : _hp(100)
        , _maxHp(100)
        , _ep(100)
        , _maxEp(100)
        , _level(1)
        , _name(name)
        , _meleeDamage(30)
        , _rangeDamage(20)
        , _damageReduction(5) {
    std::cout << "FR4G-TP " << _name << " says "
              << "\"Let's get this party started!\"." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
        : _hp(other._hp)
        , _maxHp(other._maxHp)
        , _ep(other._ep)
        , _maxEp(other._maxEp)
        , _level(other._level)
        , _name(other._name)
        , _meleeDamage(other._meleeDamage)
        , _rangeDamage(other._rangeDamage)
        , _damageReduction(other._damageReduction) {
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

    if (_maxHp - _hp <= amount) {
        _hp = _maxHp;
        std::cout << "FR4G-TP " << _name << " is at max HP!" << std::endl;
    } else {
        _hp += amount;
        std::cout << "FR4G-TP " << _name << " now has " << _hp << " HP!" << std::endl;
    }
}

void FragTrap::vaulthunter_dot_exe(const std::string& target) {
    static const unsigned _vhExeEp = 25;

    if (_ep < _vhExeEp) {
        std::cout << "FR4G-TP " << _name << " says "
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

    static const FragTrap::attack package_attacks[] = {
            &FragTrap::rangedAttack,
            &FragTrap::rangedAttack,
            &FragTrap::meleeAttack,
            &FragTrap::meleeAttack,
            &FragTrap::rangedAttack,
            &FragTrap::meleeAttack,
    };

    static const unsigned num_choices = 6;
    const size_t choice = rand() % num_choices;

    std::cout << "FR4G-TP " << _name << package_names[choice] << std::endl;
    (this->*package_attacks[choice])(target);
}
