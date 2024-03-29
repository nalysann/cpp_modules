#include "Zombie.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

std::string Zombie::_getRandomName(size_t length) {
    std::string name;
    name.reserve(length);

    static const std::string alphanum(
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz");

    for (size_t i = 0; i < length; ++i) {
        name.push_back(alphanum[rand() % alphanum.size()]);
    }

    return name;
}

Zombie::Zombie(const std::string& type, const std::string& name)
        : _type(type)
        , _name(name) {}

void Zombie::announce() const {
    std::cout << "<" << _name << " (" << _type << ")> "
              << "Braiiiiiiinnnssss..." << std::endl;
}
