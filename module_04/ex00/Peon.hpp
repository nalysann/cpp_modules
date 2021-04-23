#ifndef PEON_HPP
#define PEON_HPP

#include <string>

#include "Victim.hpp"

class Peon : public Victim {
  public:
    Peon();
    explicit Peon(const std::string& name);
    Peon(const Peon& other);
    Peon& operator=(const Peon& other);
    ~Peon();

    void getPolymorphed() const;
};

#endif
