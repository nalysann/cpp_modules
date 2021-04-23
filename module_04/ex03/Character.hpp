#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
  public:
    Character();
    explicit Character(const std::string& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    const std::string& getName() const;

    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

  private:
    static const int MAX_ITEMS = 4;

    void _clearInventory();

    std::string _name;
    AMateria* _inventory[MAX_ITEMS];
};

#endif
