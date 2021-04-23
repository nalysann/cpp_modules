#include <iostream>

#include "AlienAtomizer.hpp"
#include "AWeapon.hpp"
#include "Character.hpp"
#include "Deathclaw.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main() {
    {
        Character* me = new Character("me");

        std::cout << *me;

        Enemy* b = new RadScorpion();

        AWeapon* pr = new PlasmaRifle();
        AWeapon* pf = new PowerFist();

        me->equip(pr);
        std::cout << *me;
        me->equip(pf);

        me->attack(b);
        std::cout << *me;
        me->equip(pr);
        std::cout << *me;
        me->attack(b);
        std::cout << *me;
        me->attack(b);
        std::cout << *me;

        delete me;
        delete pr;
        delete pf;
    }

    std::cout << std::endl;

    {
        Character* me = new Character("Pepega");

        std::cout << *me;

        Enemy* sm = new SuperMutant();

        AWeapon* pr = new PlasmaRifle();
        AWeapon* pf = new PowerFist();

        me->equip(pr);
        std::cout << *me;
        me->attack(sm);
        std::cout << *me;
        me->attack(sm);
        std::cout << *me;
        std::cout << "Enemy has " << sm->getHP() << " HP left!" << std::endl;

        me->equip(pf);
        std::cout << *me;
        me->attack(sm);
        std::cout << *me;
        me->attack(sm);
        std::cout << *me;
        std::cout << "Enemy has " << sm->getHP() << " HP left!" << std::endl;

        me->equip(pr);
        std::cout << *me;
        me->attack(sm);
        std::cout << *me;
        me->attack(sm);
        std::cout << *me;
        std::cout << "Enemy has " << sm->getHP() << " HP left!" << std::endl;

        me->equip(pf);
        std::cout << *me;
        me->attack(sm);
        std::cout << *me;
        me->recoverAP();
        me->attack(sm);
        std::cout << *me;

        me->recoverAP();
        std::cout << *me;
        me->recoverAP();
        std::cout << *me;
        me->recoverAP();
        std::cout << *me;
        me->recoverAP();
        std::cout << *me;
        me->recoverAP();
        std::cout << *me;

        delete me;
        delete pr;
        delete pf;
    }

    std::cout << std::endl;

    {
        Character* me = new Character("N00B");

        std::cout << *me;

        Enemy* d = new Deathclaw();

        AWeapon* pr = new PlasmaRifle();
        AWeapon* pf = new PowerFist();
        AWeapon* aa = new AlienAtomizer();

        me->equip(pr);
        std::cout << *me;
        me->attack(d);
        std::cout << *me;
        me->attack(d);
        std::cout << *me;
        std::cout << "Enemy has " << d->getHP() << " HP left!" << std::endl;

        me->equip(pf);
        std::cout << *me;
        me->attack(d);
        std::cout << *me;
        me->attack(d);
        std::cout << *me;
        std::cout << "Enemy has " << d->getHP() << " HP left!" << std::endl;

        me->equip(aa);
        std::cout << *me;
        me->attack(d);
        std::cout << *me;
        me->attack(d);
        std::cout << *me;
        std::cout << "Enemy has " << d->getHP() << " HP left!" << std::endl;

        me->recoverAP();
        std::cout << *me;
        me->attack(d);
        std::cout << *me;
        me->recoverAP();
        me->recoverAP();
        me->recoverAP();
        me->recoverAP();
        std::cout << *me;
        me->attack(d);
        std::cout << *me;

        delete me;
        delete pr;
        delete pf;
        delete aa;
    }
}
