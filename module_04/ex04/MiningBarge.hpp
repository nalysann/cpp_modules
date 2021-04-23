#ifndef MINING_BARGE_HPP
#define MINING_BARGE_HPP

#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"

class MiningBarge {
  public:
    MiningBarge();
    MiningBarge(const MiningBarge& other);
    MiningBarge& operator=(const MiningBarge& other);
    ~MiningBarge();

    void equip(IMiningLaser* laser);
    void mine(IAsteroid* asteroid) const;

  private:
    static const int MAX_LASERS = 4;

    void _clear();

    IMiningLaser* _lasers[MAX_LASERS];
};

#endif
