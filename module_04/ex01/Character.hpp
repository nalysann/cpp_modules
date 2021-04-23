#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
  public:
    Character();
    explicit Character(const std::string& name);
    Character(Character const& other);
    Character& operator=(const Character& other);
    ~Character();

    const std::string& getName() const;
    int getAP() const;
    AWeapon* getWeapon() const;

    void recoverAP();
    void equip(AWeapon* weapon);
    void attack(Enemy* enemy);

  private:
    static const int MAX_AP = 40;
    static const int REC_AP = 10;

    std::string _name;
    int _ap;
    AWeapon* _weapon;
};

std::ostream& operator<<(std::ostream& os, const Character& character);

#endif
