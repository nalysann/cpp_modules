#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
        : AMateria("ice") {}

Ice::Ice(const Ice& other)
        : AMateria(other) {}

Ice& Ice::operator=(const Ice& other) {
    _type = other._type;
    _xp = other._xp;

    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    AMateria::use(target);
}
