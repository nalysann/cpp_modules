#include <iostream>
#include <string>

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

Character::Character(const std::string& name)
        : _name(name)
        , _ap(MAX_AP)
        , _weapon(NULL) {}

Character::Character(const Character& other)
        : _name(other._name)
        , _ap(other._ap)
        , _weapon(NULL) {}

Character& Character::operator=(const Character& other) {
    _name = other._name;
    _ap = other._ap;
    _weapon = NULL;

    return *this;
}

Character::~Character() {}

const std::string& Character::getName() const {
    return _name;
}

int Character::getAP() const {
    return _ap;
}

AWeapon* Character::getWeapon() const {
    return _weapon;
}

void Character::recoverAP() {
    if (MAX_AP - _ap < REC_AP) {
        _ap = MAX_AP;
    } else {
        _ap += REC_AP;
    }
}

void Character::equip(AWeapon* weapon) {
    _weapon = weapon;
}

void Character::attack(Enemy* enemy) {
    if (!_weapon || _ap < _weapon->getAPCost()) {
        return;
    }

    std::cout << _name << " attacks " << enemy->getType()
              << " with a " << _weapon->getName() << std::endl;
    _weapon->attack();
    _ap -= _weapon->getAPCost();

    enemy->takeDamage(_weapon->getDamage());
    if (enemy->getHP() <= 0) {
        delete enemy;
    }
}

std::ostream& operator<<(std::ostream& os, const Character& character) {
    return os << character.getName() << " has "
              << character.getAP() << " AP and "
              << (character.getWeapon() ? "wields a " + character.getWeapon()->getName()
                                        : "is unarmed")
              << std::endl;
}
