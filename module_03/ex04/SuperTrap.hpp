#ifndef SUPER_TRAP_HPP
#define SUPER_TRAP_HPP

#include <string>

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
  public:
    SuperTrap();
    explicit SuperTrap(const std::string& name);
    SuperTrap(const SuperTrap& other);
    SuperTrap& operator=(const SuperTrap& other);
    ~SuperTrap();
};

#endif
