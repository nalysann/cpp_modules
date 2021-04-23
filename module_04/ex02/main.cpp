#include <iostream>

#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"

int main() {
    {
        ISpaceMarine *bob = new TacticalMarine;
        ISpaceMarine *jim = new AssaultTerminator;

        ISquad *vlc = new Squad;
        vlc->push(bob);
        vlc->push(jim);
        for (int i = 0; i < vlc->getCount(); ++i) {
            ISpaceMarine *cur = vlc->getUnit(i);
            cur->battleCry();
            cur->rangedAttack();
            cur->meleeAttack();
        }
        delete vlc;
    }

    std::cout << std::endl;

    {
        ISpaceMarine* bob = new TacticalMarine;
        ISpaceMarine* jim = new AssaultTerminator;
        ISpaceMarine* ron = new TacticalMarine;

        Squad* vlc = new Squad;

        vlc->push(bob);
        vlc->push(bob);
        vlc->push(jim);
        vlc->push(jim);
        vlc->push(ron);
        vlc->push(ron);
        vlc->push(NULL);

        for (int i = 0; i < vlc->getCount(); ++i) {
            ISpaceMarine* cur = vlc->getUnit(i);
            cur->battleCry();
            cur->rangedAttack();
            cur->meleeAttack();
        }

        std::cout << "Current size of vlc: " << vlc->getCount() << std::endl;

        ISpaceMarine* unit = vlc->getUnit(-1);
        if (unit) {
            std::cout << "I'm not supposed to be here..." << std::endl;
        }

        unit = vlc->getUnit(42);
        if (unit) {
            std::cout << "I'm not supposed to be here..." << std::endl;
        }

        Squad* new_vlc = new Squad(*vlc);

        for (int i = 0; i < 21; ++i) {
            new_vlc->push(new TacticalMarine);
        }

        std::cout << "Current size of vlc: " << vlc->getCount() << std::endl;
        std::cout << "Current size of new_vlc: " << new_vlc->getCount() << std::endl;

        *vlc = *new_vlc;

        std::cout << "Current size of vlc: " << vlc->getCount() << std::endl;
        std::cout << "Current size of new_vlc: " << new_vlc->getCount() << std::endl;

        delete vlc;
        delete new_vlc;
    }
}
