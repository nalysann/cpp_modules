#ifndef I_SQUAD_HPP
#define I_SQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad {
  public:
    virtual ~ISquad() {}
    virtual int getCount() const = 0;
    virtual ISpaceMarine* getUnit(int) const = 0;
    virtual int push(ISpaceMarine*) = 0;
};

#endif
