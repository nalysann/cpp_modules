#ifndef POWER_FIST_HPP
#define POWER_FIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
  public:
    PowerFist();
    PowerFist(const PowerFist& other);
    PowerFist& operator=(const PowerFist& other);
    ~PowerFist();

    void attack() const;
};

#endif
