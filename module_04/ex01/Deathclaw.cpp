#include <iostream>

#include "Deathclaw.hpp"
#include "Enemy.hpp"

Deathclaw::Deathclaw()
        : Enemy(200, "Deathclaw") {
    std::cout << "* rrrraaaawwwrrr *" << std::endl;
}

Deathclaw::Deathclaw(const Deathclaw& other)
        : Enemy(other) {
    std::cout << "* rrrraaaawwwrrr *" << std::endl;
}

Deathclaw& Deathclaw::operator=(const Deathclaw& other) {
    _hp = other._hp;
    _type = other._type;

    std::cout << "* rrrraaaawwwrrr *" << std::endl;

    return *this;
}

Deathclaw::~Deathclaw() {
    std::cout << "* ghhhhh *" << std::endl;
}

void Deathclaw::takeDamage(int damage) {
    Enemy::takeDamage(damage - 5);
}
