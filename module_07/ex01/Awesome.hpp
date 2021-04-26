#ifndef AWESOME_HPP
#define AWESOME_HPP

#include <iostream>

class Awesome {
  public:
    Awesome();
    explicit Awesome(int n);
    Awesome(const Awesome&);
    Awesome& operator=(const Awesome&);
    ~Awesome();

    int getN() const;

    bool operator==(const Awesome& other) const;
    bool operator!=(const Awesome& other) const;
    bool operator>(const Awesome& other) const;
    bool operator<(const Awesome& other) const;
    bool operator>=(const Awesome& other) const;
    bool operator<=(const Awesome& other) const;

  private:
    int _n;
};

std::ostream& operator<<(std::ostream& os, const Awesome& awesome);

#endif
