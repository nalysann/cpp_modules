#include <cstdlib>
#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
        : _hp(100)
        , _maxHp(100)
        , _ep(50)
        , _maxEp(50)
        , _level(1)
        , _name(name)
        , _meleeDamage(20)
        , _rangeDamage(15)
        , _damageReduction(3) {
    std::cout << "SC4V-TP " << _name << " says "
              << "\"Here I come to save the day, beware!\"." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
        : _hp(other._hp)
        , _maxHp(other._maxHp)
        , _ep(other._ep)
        , _maxEp(other._maxEp)
        , _level(other._level)
        , _name(other._name)
        , _meleeDamage(other._meleeDamage)
        , _rangeDamage(other._rangeDamage)
        , _damageReduction(other._damageReduction) {
    std::cout << "SC4V-TP " << _name << " says "
              << "\"Another day in paradise!\"." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    _hp = other._hp;
    _maxHp = other._maxHp;
    _ep = other._ep;
    _maxEp = other._maxEp;
    _level = other._level;
    _name = other._name;
    _meleeDamage = other._meleeDamage;
    _rangeDamage = other._rangeDamage;
    _damageReduction = other._damageReduction;

    std::cout << "SC4V-TP " << _name << " says "
              << "\"What, again?\"." << std::endl;

    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "SC4V-TP " << _name << " mumbles "
              << "\"This isn't over...\" and disappears." << std::endl;
}

void ScavTrap::meleeAttack(const std::string& target) const {
    std::cout << "SC4V-TP " << _name << " attacks " << target << " in melee, causing "
              << _meleeDamage << " points of damage!" << std::endl;
}

void ScavTrap::rangedAttack(const std::string& target) const {
    std::cout << "SC4V-TP " << _name << " attacks " << target << " at range, causing "
              << _rangeDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned amount) {
    std::cout << "SC4V-TP " << _name << " is under attack!" << std::endl;

    if (_hp == 0) {
        std::cout << "SC4V-TP " << _name << " sobs: "
                  << "\"You can't hurt me more then this!\"." << std::endl;
        return;
    }

    if (amount <= _damageReduction) {
        std::cout << "SC4V-TP " << _name << " sings "
                  << "\"Can't touch this!\"." << std::endl;
        return;
    }

    amount -= _damageReduction;

    if (_hp <= amount) {
        _hp = 0;
        std::cout << "SC4V-TP " << _name << " says "
                  << "\"Really?\" and dies." << std::endl;
    } else {
        _hp -= amount;
        std::cout << "Damn it! " << "SC4V-TP " << _name
                  << " has " << _hp << " HP left." << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned amount) {
    std::cout << "SC4V-TP " << _name << " spots health and says "
              << "\"Niiice!\"." << std::endl;

    if (_maxHp - _hp <= amount) {
        _hp = _maxHp;
        std::cout << "SC4V-TP " << _name << " is at max HP!" << std::endl;
    } else {
        _hp += amount;
        std::cout << "SC4V-TP " << _name << " now has " << _hp << " HP!" << std::endl;
    }
}

void ScavTrap::challengeNewcomer(const std::string& target) {
    static const std::string challenges[] = {
            "dance off",
            "pillow duel",
            "karaoke battle",
            "russian roulette",
            "cooking competition",
            "spelling bee",
    };

    static const unsigned num_choices = 6;
    const size_t choice = rand() % num_choices;

    std::cout << "SC4V-TP " << _name << " challenges " << target
              << " to a " << challenges[choice] << '.' << std::endl;
}
