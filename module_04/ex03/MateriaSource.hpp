#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <string>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(const std::string& type);

  private:
    static const int MAX_ITEMS = 4;

    void _clearInventory();

    AMateria* _inventory[MAX_ITEMS];
};

#endif
