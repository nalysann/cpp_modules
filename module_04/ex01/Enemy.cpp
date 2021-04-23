#include <string>

#include "Enemy.hpp"

Enemy::Enemy(int hp, const std::string& type)
        : _hp(hp)
        , _type(type) {}

Enemy::Enemy(const Enemy& other)
        : _hp(other._hp)
        , _type(other._type) {}

Enemy& Enemy::operator=(const Enemy& other) {
    _hp = other._hp;
    _type = other._type;

    return *this;
}

Enemy::~Enemy() {}

int Enemy::getHP() const {
    return _hp;
}

const std::string& Enemy::getType() const {
    return _type;
}

void Enemy::takeDamage(int damage) {
    if (damage < 0) {
        return;
    }

    if (_hp < damage) {
        _hp = 0;
    } else {
        _hp -= damage;
    }
}
