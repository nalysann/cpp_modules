#include <cmath>
#include <iostream>
#include <sstream>

#include "Fixed.hpp"

Fixed::Fixed()
        : _rawBits(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) {
    _rawBits = other._rawBits;
}

Fixed& Fixed::operator=(const Fixed& other) {
    _rawBits = other._rawBits;
    return *this; //
}

Fixed::Fixed(const int number)
        : _rawBits(number << _FRAC_SIZE) {
}

Fixed::Fixed(const float number)
        : _rawBits(static_cast<int>(roundf(number * (1 << _FRAC_SIZE)))) {
}

Fixed::Fixed(const std::string& expr, size_t pos) {
    std::istringstream is(expr);
    is.seekg(pos);
    float number;
    is >> number;
    std::cout << "STR CTOR: " << number << std::endl;
    _rawBits = static_cast<int>(roundf(number * (1 << _FRAC_SIZE)));
}

int Fixed::getRawBits() const {
    return _rawBits;
}

void Fixed::setRawBits(const int raw) {
    _rawBits = raw;
}

int Fixed::toInt() const {
    return _rawBits >> _FRAC_SIZE;
}

float Fixed::toFloat() const {
    return static_cast<float>(_rawBits) / (1 << _FRAC_SIZE);
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
    _rawBits = static_cast<int>((static_cast<long long>(_rawBits) * other._rawBits) >> _FRAC_SIZE);
    return *this;
}

Fixed& Fixed::operator/=(const Fixed& other) {
    _rawBits = static_cast<int>((static_cast<long long>(_rawBits) << _FRAC_SIZE) / other._rawBits);
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

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    return os << fixed.toFloat();
}
