#ifndef DEEP_CORE_MINER_HPP
#define DEEP_CORE_MINER_HPP

#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {
  public:
    DeepCoreMiner();
    DeepCoreMiner(const DeepCoreMiner&);
    DeepCoreMiner& operator=(const DeepCoreMiner&);
    ~DeepCoreMiner();

    void mine(IAsteroid* asteroid);
    IMiningLaser* clone() const;
};

#endif
