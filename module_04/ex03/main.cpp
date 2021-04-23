#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main() {
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << std::endl;

    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Ice());

        AMateria* cure = new Cure();
        src->learnMateria(cure);
        AMateria* ice = new Ice();
        src->learnMateria(ice);

        ICharacter* me = new Character("me");

        me->unequip(0);
        me->unequip(42);
        me->unequip(-1);

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        AMateria* xp_test;
        xp_test = src->createMateria("cure");
        me->equip(xp_test);

        tmp = src->createMateria("ice");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        std::cout << "Current XP: " << xp_test->getXP() << std::endl;
        me->use(3, *bob);
        std::cout << "Current XP: " << xp_test->getXP() << std::endl;
        me->use(3, *me);
        std::cout << "Current XP: " << xp_test->getXP() << std::endl;
        me->use(3, *bob);
        std::cout << "Current XP: " << xp_test->getXP() << std::endl;

        me->use(-11, *bob);
        me->use(44, *bob);

        me->unequip(3);
        me->use(3, *bob);

        delete bob;
        delete xp_test;
        delete tmp;
        delete me;
        delete ice;
        delete cure;
        delete src;
    }
}
