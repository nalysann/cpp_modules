#ifndef NINJA_TRAP_HPP
#define NINJA_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap {
  public:
    explicit NinjaTrap(const std::string& name);
    NinjaTrap(const NinjaTrap& other);
    NinjaTrap& operator=(const NinjaTrap& other);
    ~NinjaTrap();

    void ninjaShoebox(ClapTrap& clap) const;
    void ninjaShoebox(FragTrap& frag) const;
    void ninjaShoebox(NinjaTrap& ninja) const;
    void ninjaShoebox(ScavTrap& scav) const;
};

#endif
