#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>

#include "Weapon.hpp"

class HumanA {
  public:
    HumanA(const std::string& name, const Weapon& weapon);

    void attack() const;

  private:
    const std::string _name;
    const Weapon& _weapon;
};

#endif
