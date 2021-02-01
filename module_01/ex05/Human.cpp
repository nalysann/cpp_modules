#include <string>

#include "Brain.hpp"
#include "Human.hpp"

const Brain& Human::getBrain() const {
    return _brain;
}

std::string Human::identify() const {
    return _brain.identify();
}
