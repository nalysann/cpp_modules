#include <string>

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character(const std::string& name)
        : _name(name)
        , _inventory() {}

Character::Character(const Character& other)
        : _name(other._name)
        , _inventory() {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;

        _clearInventory();

        for (int i = 0; i < MAX_ITEMS; ++i) {
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            }
        }
    }

    return *this;
}

Character::~Character() {
    _clearInventory();
}

const std::string& Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (0 <= idx && idx < MAX_ITEMS) {
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (0 <= idx && idx < MAX_ITEMS && _inventory[idx]) {
        _inventory[idx]->use(target);
    }
}

void Character::_clearInventory() {
    for (int i = 0; i < MAX_ITEMS; ++i) {
        delete _inventory[i];
    }
}
