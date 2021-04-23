#ifndef ALIEN_ATOMIZER_HPP
#define ALIEN_ATOMIZER_HPP

#include "AWeapon.hpp"

class AlienAtomizer : public AWeapon {
  public:
    AlienAtomizer();
    AlienAtomizer(const AlienAtomizer& other);
    AlienAtomizer& operator=(const AlienAtomizer& other);
    ~AlienAtomizer();

    void attack() const;
};

#endif
