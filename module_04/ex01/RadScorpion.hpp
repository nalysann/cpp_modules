#ifndef RAD_SCORPION_HPP
#define RAD_SCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy {
  public:
    RadScorpion();
    RadScorpion(const RadScorpion& other);
    RadScorpion& operator=(const RadScorpion& other);
    ~RadScorpion();
};

#endif
