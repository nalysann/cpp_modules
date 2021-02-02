#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(const std::string& type)
    : _zombieType(type) {}

void ZombieEvent::setZombieType(const std::string& type) {
    _zombieType = type;
}

Zombie* ZombieEvent::newZombie(const std::string& name) const {
    return new Zombie(_zombieType, name);
}
