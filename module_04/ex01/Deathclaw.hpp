#ifndef DEATHCLAW_HPP
#define DEATHCLAW_HPP

#include "Enemy.hpp"

class Deathclaw : public Enemy {
  public:
    Deathclaw();
    Deathclaw(const Deathclaw& other);
    Deathclaw& operator=(const Deathclaw& other);
    ~Deathclaw();

    void takeDamage(int damage);
};

#endif
