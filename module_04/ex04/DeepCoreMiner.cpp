#include <iostream>

#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"

DeepCoreMiner::DeepCoreMiner() {}

DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner&) {}

DeepCoreMiner& DeepCoreMiner::operator=(const DeepCoreMiner&) {
    return *this;
}

DeepCoreMiner::~DeepCoreMiner() {}

void DeepCoreMiner::mine(IAsteroid* asteroid) {
    std::cout << "* mining deep... got " << asteroid->beMined(this) << "! *" << std::endl;
}

IMiningLaser* DeepCoreMiner::clone() const {
    return new DeepCoreMiner();
}
