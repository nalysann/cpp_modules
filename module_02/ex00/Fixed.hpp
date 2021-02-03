#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    int getRawBits() const;
    void setRawBits(const int raw);

  private:
    static const int _FRAC_SIZE = 8;

    int _rawBits;
};

#endif
