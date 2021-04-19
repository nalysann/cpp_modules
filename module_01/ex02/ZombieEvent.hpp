#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

#include <string>

#include "Zombie.hpp"

class ZombieEvent {
  public:
    explicit ZombieEvent(const std::string& zombie_type = "sniffer");

    void setZombieType(const std::string& zombie_type);
    Zombie* newZombie(const std::string& name) const;

  private:
    std::string _zombie_type;
};

#endif
