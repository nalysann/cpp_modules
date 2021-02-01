#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main () {
    {
        Weapon club("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("daedric club");
        bob.attack();
    }

    {
        Weapon club("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("daedric club");
        jim.attack();
    }
}