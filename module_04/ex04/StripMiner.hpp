#ifndef STRIP_MINER_HPP
#define STRIP_MINER_HPP

#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {
  public:
    StripMiner();
    StripMiner(const StripMiner&);
    StripMiner& operator=(const StripMiner&);
    ~StripMiner();

    void mine(IAsteroid* asteroid);
    IMiningLaser* clone() const;
};

#endif
