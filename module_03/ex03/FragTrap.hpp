#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  public:
    FragTrap();
    explicit FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void vaulthunter_dot_exe(const std::string& target);
};

#endif
