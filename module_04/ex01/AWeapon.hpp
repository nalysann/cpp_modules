#ifndef A_WEAPON_HPP
#define A_WEAPON_HPP

#include <string>

class AWeapon {
  public:
    AWeapon();
    AWeapon(const std::string& name, int ap_cost, int damage);
    AWeapon(const AWeapon& other);
    AWeapon& operator=(const AWeapon& other);
    virtual ~AWeapon();

    const std::string& getName() const;
    int getAPCost() const;
    int getDamage() const;

    virtual void attack() const = 0;

  protected:
    std::string _name;
    int _ap_cost;
    int _damage;
};

#endif
