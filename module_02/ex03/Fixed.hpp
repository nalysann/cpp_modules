#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
  public:
    Fixed();
    Fixed(const Fixed& other);
    explicit Fixed(int number);
    explicit Fixed(float number);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int rawBits);

    int toInt() const;
    float toFloat() const;

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator+=(const Fixed& other);
    Fixed& operator-=(const Fixed& other);
    Fixed& operator*=(const Fixed& other);
    Fixed& operator/=(const Fixed& other);

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

  private:
    static const int FRAC_SIZE = 8;

    int _rawBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

Fixed& min(Fixed& a, Fixed& b);
const Fixed& min(const Fixed& a, const Fixed& b);
Fixed& max(Fixed& a, Fixed& b);
const Fixed& max(const Fixed& a, const Fixed& b);

#endif
