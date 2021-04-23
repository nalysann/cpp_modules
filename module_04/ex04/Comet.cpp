#include <string>

#include "Comet.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

Comet::Comet()
        : _name("Comet") {}

Comet::Comet(const Comet& other)
        : _name(other._name) {}

Comet& Comet::operator=(const Comet& other) {
    _name = other._name;

    return *this;
}

Comet::~Comet() {}

std::string Comet::beMined(DeepCoreMiner*) const {
    return "Meium";
}

std::string Comet::beMined(StripMiner*) const {
    return "Tartarite";
}

std::string Comet::getName() const {
    return _name;
}
