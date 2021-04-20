#include <cmath>
#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed()
        : _rawBits(0) {}

Fixed::Fixed(const Fixed& other) {
    _rawBits = other._rawBits;
}

Fixed::Fixed(int number)
        : _rawBits(number << FRAC_SIZE) {
}

Fixed::Fixed(float number)
        : _rawBits(static_cast<int>(roundf(number * (1 << FRAC_SIZE)))) {
}

Fixed& Fixed::operator=(const Fixed& other) {
    _rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    return _rawBits;
}

void Fixed::setRawBits(int rawBits) {
    _rawBits = rawBits;
}

int Fixed::toInt() const {
    return _rawBits >> FRAC_SIZE;
}

float Fixed::toFloat() const {
    return static_cast<float>(_rawBits) / (1 << FRAC_SIZE);
}

bool Fixed::operator>(const Fixed& other) const {
    return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(*this) += other;
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(*this) -= other;
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(*this) *= other;
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(*this) /= other;
}

Fixed& Fixed::operator+=(const Fixed& other) {
    _rawBits += other._rawBits;
    return *this;
}

Fixed& Fixed::operator-=(const Fixed& other) {
    _rawBits -= other._rawBits;
    return *this;
}

Fixed& Fixed::operator*=(const Fixed& other) {
    _rawBits = static_cast<int>((static_cast<long long>(_rawBits) * other._rawBits) >> FRAC_SIZE);
    return *this;
}

Fixed& Fixed::operator/=(const Fixed& other) {
    _rawBits = static_cast<int>((static_cast<long long>(_rawBits) << FRAC_SIZE) / other._rawBits);
    return *this;
}

Fixed& Fixed::operator++() {
    ++_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed ret;
    ret._rawBits = _rawBits++;
    return ret;
}

Fixed& Fixed::operator--() {
    --_rawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed ret;
    ret._rawBits = _rawBits--;
    return ret;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    return os << fixed.toFloat();
}

Fixed& min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

const Fixed& min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

Fixed& max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

const Fixed& max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}
