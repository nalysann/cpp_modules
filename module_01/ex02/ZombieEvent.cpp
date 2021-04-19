#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(const std::string& zombie_type)
        : _zombie_type(zombie_type) {}

void ZombieEvent::setZombieType(const std::string& zombie_type) {
    _zombie_type = zombie_type;
}

Zombie* ZombieEvent::newZombie(const std::string& name) const {
    return new Zombie(_zombie_type, name);
}
