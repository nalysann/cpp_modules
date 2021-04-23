#ifndef TACTICAL_MARINE_HPP
#define TACTICAL_MARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
  public:
    TacticalMarine();
    TacticalMarine(const TacticalMarine&);
    TacticalMarine& operator=(const TacticalMarine&);
    ~TacticalMarine();

    ISpaceMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif
