#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP

#include <string>

#include "AMateria.hpp"

class IMateriaSource {
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif
