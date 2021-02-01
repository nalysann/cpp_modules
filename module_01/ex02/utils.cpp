#include <string>

#include "Zombie.hpp"

void randomChump(const std::string& type) {
    Zombie zombie(type);
    zombie.announce();
}
