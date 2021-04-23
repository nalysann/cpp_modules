#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
        : AMateria("cure") {}

Cure::Cure(const Cure& other)
        : AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {
    _type = other._type;
    _xp = other._xp;

    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    AMateria::use(target);
}
