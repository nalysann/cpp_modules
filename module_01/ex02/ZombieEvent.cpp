#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(const std::string& type)
    : _zombie_type(type) {}

void ZombieEvent::setZombieType(const std::string& type) {
    _zombie_type = type;
}

Zombie* ZombieEvent::newZombie(const std::string& name) const {
    return new Zombie(_zombie_type, name);
}
