#include <iostream>

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(size_t size)
        : _size(size)
        , _horde(new Zombie[_size]) {}

ZombieHorde::~ZombieHorde() {
    delete[] _horde;
}

void ZombieHorde::announce() const {
    std::cout << "Psst, wanna buy some zombies? "
                 "We have " << _size << " zombies to sell!"
              << std::endl;

    for (size_t i = 0; i < _size; ++i) {
        _horde[i].announce();
    }
}
