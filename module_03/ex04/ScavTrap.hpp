#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  public:
    explicit ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    void challengeNewcomer(const std::string& target);
};

#endif
