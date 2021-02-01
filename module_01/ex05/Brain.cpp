#include <string>
#include <sstream>

#include "Brain.hpp"

std::string Brain::identify() const {
    std::stringstream os;
    os << this;
    return os.str();
}
