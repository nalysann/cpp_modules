#ifndef ZOMBIE_HORDE_HPP
#define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {
  public:
    explicit ZombieHorde(size_t size = 13);
    ~ZombieHorde();

    void announce() const;

  private:
    const size_t _size;
    const Zombie* const _horde;
};

#endif
