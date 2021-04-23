#include <iostream>

#include "Enemy.hpp"
#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
        : Enemy(80, "RadScorpion") {
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion& other)
        : Enemy(other) {
    std::cout << "* click click click *" << std::endl;
}

RadScorpion& RadScorpion::operator=(const RadScorpion& other) {
    _hp = other._hp;
    _type = other._type;

    std::cout << "* click click click *" << std::endl;

    return *this;
}

RadScorpion::~RadScorpion() {
    std::cout << "* SPROTCH *" << std::endl;
}
