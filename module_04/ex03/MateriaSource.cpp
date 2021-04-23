#include <string>

#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
        : _inventory() {}

MateriaSource::MateriaSource(const MateriaSource& other)
        : _inventory() {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        _clearInventory();

        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            }
        }
    }

    return *this;
}

MateriaSource::~MateriaSource() {
    _clearInventory();
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (_inventory[i] && _inventory[i]->getType() == type) {
            return _inventory[i]->clone();
        }
    }
    return NULL;
}

void MateriaSource::_clearInventory() {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        delete _inventory[i];
    }
}
