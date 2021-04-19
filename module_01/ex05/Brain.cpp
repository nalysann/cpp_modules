#include <sstream>
#include <string>

#include "Brain.hpp"

std::string Brain::identify() const {
    std::stringstream os;
    os << this;
    return os.str();
}
