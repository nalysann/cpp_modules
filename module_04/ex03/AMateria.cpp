#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const std::string& type)
        : _type(type)
        , _xp(0) {}

AMateria::AMateria(const AMateria& other)
        : _type(other._type)
        , _xp(other._xp) {}

AMateria& AMateria::operator=(const AMateria& other) {
    _type = other._type;
    _xp = other._xp;

    return *this;
}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const {
    return _type;
}

unsigned AMateria::getXP() const {
    return _xp;
}

void AMateria::use(ICharacter&) {
    _xp += XP_INC;
}
