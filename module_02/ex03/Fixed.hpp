#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    explicit Fixed(const int number);
    explicit Fixed(const float number);

    explicit Fixed(const std::string& expr, size_t pos = 0);

    int getRawBits() const;
    void setRawBits(const int raw);

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

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

  private:
    static const int _FRAC_SIZE = 8;

    int _rawBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
