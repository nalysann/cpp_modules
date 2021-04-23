#ifndef I_MINING_LASER_HPP
#define I_MINING_LASER_HPP

#include "IAsteroid.hpp"

class IMiningLaser {
  public:
    virtual ~IMiningLaser() {}
    virtual void mine(IAsteroid*) = 0;
    virtual IMiningLaser* clone() const = 0;
};

#endif
