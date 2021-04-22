#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include <string>

#include "Victim.hpp"

class Sorcerer {
  public:
    Sorcerer();
    Sorcerer(const std::string& name, const std::string& title);
    Sorcerer(const Sorcerer& other);
    Sorcerer& operator=(const Sorcerer& other);
    ~Sorcerer();

    const std::string& getName() const;
    const std::string& getTitle() const;

    void polymorph(const Victim& victim) const;

  private:
    std::string _name;
    std::string _title;
};

std::ostream& operator<<(std::ostream& os, const Sorcerer& sorcerer);

#endif
