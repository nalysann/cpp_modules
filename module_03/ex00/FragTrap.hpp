#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>

class FragTrap {
  public:
    explicit FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void meleeAttack(const std::string& target) const;
    void rangedAttack(const std::string& target) const;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void vaulthunter_dot_exe(const std::string& targert) const;

  private:
    static const unsigned _maxHp = 100;
    static const unsigned _maxEp = 100;
    static const unsigned _meleeDamage = 30;
    static const unsigned _rangeDamage = 20;
    static const unsigned _damageReduction = 5;

    unsigned _hp;
    unsigned _ep;
    unsigned _level;
    const std::string _name;
};

#endif
