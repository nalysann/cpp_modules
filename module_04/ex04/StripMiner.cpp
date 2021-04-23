#include <iostream>

#include "IAsteroid.hpp"
#include "StripMiner.hpp"

StripMiner::StripMiner() {}

StripMiner::StripMiner(const StripMiner&) {}

StripMiner& StripMiner::operator=(const StripMiner&) {
    return *this;
}

StripMiner::~StripMiner() {}

void StripMiner::mine(IAsteroid* asteroid) {
    std::cout << "* strip mining... got " << asteroid->beMined(this) << "! *" << std::endl;
}

IMiningLaser* StripMiner::clone() const {
    return new StripMiner();
}
