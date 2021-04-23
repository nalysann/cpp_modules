#include <iostream>

#include "Enemy.hpp"
#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
        : Enemy(170, "Super Mutant") {
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& other)
        : Enemy(other) {
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant& SuperMutant::operator=(const SuperMutant& other) {
    _hp = other._hp;
    _type = other._type;

    std::cout << "Gaaah. Me want smash heads!" << std::endl;

    return *this;
}

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage) {
    Enemy::takeDamage(damage - 3);
}
