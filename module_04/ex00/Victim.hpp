#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class Victim {
  public:
    Victim();
    explicit Victim(const std::string& name);
    Victim(const Victim& other);
    Victim& operator=(const Victim& other);
    virtual ~Victim();

    const std::string& getName() const;

    virtual void getPolymorphed() const;

  protected:
    std::string _name;
};

std::ostream& operator<<(std::ostream& os, const Victim& victim);

#endif
