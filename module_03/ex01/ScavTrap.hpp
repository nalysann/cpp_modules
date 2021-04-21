#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>

class ScavTrap {
  public:
    explicit ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    void meleeAttack(const std::string& target) const;
    void rangedAttack(const std::string& target) const;
    void takeDamage(unsigned amount);
    void beRepaired(unsigned amount);

    void challengeNewcomer(const std::string& target);

  private:
    unsigned _hp;
    unsigned _maxHp;
    unsigned _ep;
    unsigned _maxEp;
    unsigned _level;
    std::string _name;
    unsigned _meleeDamage;
    unsigned _rangeDamage;
    unsigned _damageReduction;
};

#endif
