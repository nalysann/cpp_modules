#include <iostream>

#include "Awesome.hpp"

Awesome::Awesome(int n)
        : _n(n) {}

Awesome::Awesome(const Awesome& other)
        : _n(other._n) {}

Awesome& Awesome::operator=(const Awesome& other) {
    _n = other._n;
    return *this;
}

Awesome::~Awesome() {}

int Awesome::getN() const {
    return _n;
}

bool Awesome::operator==(const Awesome& other) const {
    return _n == other._n;
}

bool Awesome::operator!=(const Awesome& other) const {
    return _n != other._n;
}

bool Awesome::operator>(const Awesome& other) const {
    return _n > other._n;
}

bool Awesome::operator<(const Awesome& other) const {
    return _n < other._n;
}

bool Awesome::operator>=(const Awesome& other) const {
    return _n >= other._n;
}

bool Awesome::operator<=(const Awesome& other) const {
    return _n <= other._n;
}

std::ostream& operator<<(std::ostream& os, const Awesome& awesome) {
    return os << "Awesome(" << awesome.getN() << ")";
}
