#ifndef PLASMA_RIFLE_HPP
#define PLASMA_RIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
  public:
    PlasmaRifle();
    PlasmaRifle(const PlasmaRifle& other);
    PlasmaRifle& operator=(const PlasmaRifle& other);
    ~PlasmaRifle();

    void attack() const;
};

#endif
