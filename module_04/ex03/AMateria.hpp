#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria {
  public:
    AMateria();
    explicit AMateria(const std::string& type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    const std::string& getType() const;
    unsigned getXP() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

  protected:
    static const unsigned XP_INC = 10;

    std::string _type;
    unsigned _xp;
};

#endif
