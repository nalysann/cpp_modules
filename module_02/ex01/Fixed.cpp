#include <cmath>
#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed()
        : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = other._rawBits;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Assignation operator called" << std::endl;
    _rawBits = other._rawBits;
    return *this;
}

Fixed::Fixed(const int number)
    : _rawBits(number << _FRAC_SIZE) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
    : _rawBits(static_cast<int>(roundf(number * (1 << _FRAC_SIZE)))) {
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}

int Fixed::toInt() const {
    return _rawBits >> _FRAC_SIZE;
}

float Fixed::toFloat() const {
    return static_cast<float>(_rawBits) / (1 << _FRAC_SIZE);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    return os << fixed.toFloat();
}
