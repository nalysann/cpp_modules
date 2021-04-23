#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
  public:
    explicit Weapon(const std::string& type = "polearm");

    const std::string& getType() const;
    void setType(const std::string& type);

  private:
    std::string _type;
};

#endif
