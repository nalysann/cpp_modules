#include <cstdlib>
#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
        : ClapTrap(100,
                   100,
                   50,
                   50,
                   1,
                   name,
                   "SC4V-TP",
                   20,
                   15,
                   3) {
    std::cout << "SC4V-TP " << _name << " says "
              << "\"Here I come to save the day, beware!\"." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
        : ClapTrap(other) {
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
    _type = other._type;
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

    std::cout << _type << ' ' << _name << " challenges " << target
              << " to a " << challenges[choice] << '.' << std::endl;
}
