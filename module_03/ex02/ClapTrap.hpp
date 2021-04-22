#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
  public:
    typedef void (ClapTrap::*attack)(const std::string&) const;

    explicit ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void meleeAttack(const std::string& target) const;
    void rangedAttack(const std::string& target) const;
    void takeDamage(unsigned amount);
    void beRepaired(unsigned amount);

  protected:
    ClapTrap(unsigned hp,
             unsigned maxHp,
             unsigned ep,
             unsigned maxEp,
             unsigned level,
             const std::string& name,
             const std::string& type,
             unsigned meleeDamage,
             unsigned rangeDamage,
             unsigned damageReduction);

    unsigned _hp;
    unsigned _maxHp;
    unsigned _ep;
    unsigned _maxEp;
    unsigned _level;
    std::string _name;
    std::string _type;
    unsigned _meleeDamage;
    unsigned _rangeDamage;
    unsigned _damageReduction;
};

#endif
