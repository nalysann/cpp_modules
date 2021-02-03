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

    int getRawBits() const;
    void setRawBits(const int raw);

    int toInt() const;
    float toFloat() const;

  private:
    static const int _FRAC_SIZE = 8;

    int _rawBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
