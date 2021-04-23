#include <cstddef>
#include <iostream>

#include "ISpaceMarine.hpp"
#include "Squad.hpp"

Squad::Squad()
        : _max_count(INITIAL_MAX_COUNT)
        , _count(0)
        , _units(new ISpaceMarine*[INITIAL_MAX_COUNT]) {
}

Squad::Squad(const Squad& other)
        : _max_count(other._max_count)
        , _count(other._count)
        , _units(new ISpaceMarine*[other._max_count]) {
    for (int i = 0; i < _count; ++i) {
        _units[i] = other._units[i]->clone();
    }
}

Squad& Squad::operator=(const Squad& other) {
    if (this == &other) {
        return *this;
    }

    _clear();

    _max_count = other._max_count;
    _count = other._count;
    _units = new ISpaceMarine*[other._max_count];

    for (int i = 0; i < _count; ++i) {
        _units[i] = other._units[i]->clone();
    }

    return *this;
}

Squad::~Squad() {
    _clear();
}

int Squad::getCount() const {
    return _count;
}

ISpaceMarine* Squad::getUnit(int idx) const {
    if (0 <= idx && idx < _count) {
        return _units[idx];
    } else {
        return NULL;
    }
}

int Squad::push(ISpaceMarine *unit) {
    if (unit == NULL || _contains(unit)) {
        return _count;
    }

    if (_count == _max_count) {
        int new_max_count = _max_count * GROWTH_RATE;
        ISpaceMarine** new_units = new ISpaceMarine*[new_max_count];

        for (int i = 0; i < _count; ++i) {
            new_units[i] = _units[i];
        }
        delete[] _units;
        _max_count = new_max_count;
        _units = new_units;
    }

    _units[_count++] = unit;

    return _count;
}

void Squad::_clear() {
    for (int i = 0; i < _count; ++i) {
        delete _units[i];
    }
    delete[] _units;
}

bool Squad::_contains(ISpaceMarine *unit) {
    for (int i = 0; i < _count; ++i) {
        if (_units[i] == unit) {
            return true;
        }
    }
    return false;
}
