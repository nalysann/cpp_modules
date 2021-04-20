#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
  public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int rawBits);

  private:
    static const int FRAC_SIZE = 8;

    int _rawBits;
};

#endif
