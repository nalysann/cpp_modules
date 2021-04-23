#ifndef SUPER_MUTANT_HPP
#define SUPER_MUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy {
  public:
    SuperMutant();
    SuperMutant(const SuperMutant& other);
    SuperMutant& operator=(const SuperMutant& other);
    ~SuperMutant();

    void takeDamage(int damage);
};

#endif
