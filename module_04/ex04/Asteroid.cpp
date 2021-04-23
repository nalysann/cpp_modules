#include <string>

#include "Asteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

Asteroid::Asteroid()
        : _name("Asteroid") {}

Asteroid::Asteroid(const Asteroid& other)
        : _name(other._name) {}

Asteroid& Asteroid::operator=(const Asteroid& other) {
    _name = other._name;

    return *this;
}

Asteroid::~Asteroid() {}

std::string Asteroid::beMined(DeepCoreMiner*) const {
    return "Dragonite";
}

std::string Asteroid::beMined(StripMiner*) const {
    return "Flavium";
}

std::string Asteroid::getName() const {
    return _name;
}
