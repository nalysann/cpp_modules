#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>

class FragTrap {
  public:
    FragTrap();
    explicit FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void meleeAttack(const std::string& target) const;
    void rangedAttack(const std::string& target) const;
    void takeDamage(unsigned amount);
    void beRepaired(unsigned amount);

    void vaulthunter_dot_exe(const std::string& target);

  private:
    typedef void (FragTrap::*_attack)(const std::string&) const;

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
