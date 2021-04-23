#include <iostream>
#include <string>

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

Character::Character(const std::string& name)
        : _name(name)
        , _ap(_max_ap)
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
    if (_max_ap - _ap < _recover_ap) {
        _ap = _max_ap;
    } else {
        _ap += _recover_ap;
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

const int Character::_max_ap = 40;
const int Character::_recover_ap = 10;
