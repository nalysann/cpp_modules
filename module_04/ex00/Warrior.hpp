#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <string>

#include "Victim.hpp"

class Warrior : public Victim {
  public:
    Warrior();
    explicit Warrior(const std::string& name);
    Warrior(const Warrior& other);
    Warrior& operator=(const Warrior& other);
    ~Warrior();

    void getPolymorphed() const;
};

#endif
