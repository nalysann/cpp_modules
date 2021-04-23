#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "MiningBarge.hpp"

MiningBarge::MiningBarge()
        : _lasers() {}

MiningBarge::MiningBarge(const MiningBarge& other)
        : _lasers() {
    for (int i = 0; i < MAX_LASERS; ++i) {
        if (other._lasers[i]) {
            _lasers[i] = other._lasers[i]->clone();
        }
    }
}

MiningBarge& MiningBarge::operator=(const MiningBarge& other) {
    if (this != &other) {
        _clear();

        for (int i = 0; i < MAX_LASERS; ++i) {
            if (other._lasers[i]) {
                _lasers[i] = other._lasers[i]->clone();
            }
        }
    }

    return *this;
}

MiningBarge::~MiningBarge() {
    _clear();
}

void MiningBarge::equip(IMiningLaser* laser) {
    for (int i = 0; i < MAX_LASERS; ++i) {
        if (!_lasers[i]) {
            _lasers[i] = laser;
            return;
        }
    }
}

void MiningBarge::mine(IAsteroid* asteroid) const {
    for (int i = 0; i < MAX_LASERS; ++i) {
        if (_lasers[i]) {
            _lasers[i]->mine(asteroid);
        }
    }
}

void MiningBarge::_clear() {
    for (int i = 0; i < MAX_LASERS; ++i) {
        delete _lasers[i];
    }
}
