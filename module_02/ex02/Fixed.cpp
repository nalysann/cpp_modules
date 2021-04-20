#include <cmath>
#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed()
        : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = other._rawBits;
}

Fixed::Fixed(int number)
        : _rawBits(number << FRAC_SIZE) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float number)
        : _rawBits(static_cast<int>(roundf(number * (1 << FRAC_SIZE)))) {
    std::cout << "Float constructor called" << std::endl;
}


Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Assignment operator called" << std::endl;
    _rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int rawBits) {
    std::cout << "setRawBits member function called" << std::endl;
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
    Fixed ret;
    ret._rawBits = _rawBits + other._rawBits;
    return ret;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed ret;
    ret._rawBits = _rawBits - other._rawBits;
    return ret;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed ret;
    ret._rawBits = static_cast<int>((static_cast<long long>(_rawBits) * other._rawBits) >> FRAC_SIZE);
    return ret;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed ret;
    ret._rawBits = static_cast<int>((static_cast<long long>(_rawBits) << FRAC_SIZE) / other._rawBits);
    return ret;
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
