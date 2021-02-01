#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

#include "Brain.hpp"

class Human {
  public:
    const Brain& getBrain() const;
    std::string identify() const;

  private:
    const Brain _brain;
};

#endif
