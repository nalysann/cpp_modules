#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>

#include "Weapon.hpp"

class HumanB {
  public:
    explicit HumanB(const std::string& name);

    void setWeapon(const Weapon& weapon);
    void attack() const;

  private:
    const std::string _name;
    const Weapon* _weapon;
};

#endif
