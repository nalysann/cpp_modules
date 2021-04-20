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

  private:
    static const int FRAC_SIZE = 8;

    int _rawBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
