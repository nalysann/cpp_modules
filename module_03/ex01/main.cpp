#include <cstdlib>
#include <ctime>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    {
        srand(time(NULL));

        FragTrap frag("Claptrap");
        FragTrap ffrag("Pepetrap");
        FragTrap fffrag(frag);

        fffrag = ffrag;

        frag.vaulthunter_dot_exe("Apollo");
        frag.takeDamage(42);
        frag.vaulthunter_dot_exe("Apollo");
        frag.takeDamage(69);
        frag.takeDamage(1);
        frag.beRepaired(50);
        frag.takeDamage(4);
        frag.vaulthunter_dot_exe("Apollo");
        frag.beRepaired(146);
        frag.vaulthunter_dot_exe("Apollo");
        frag.vaulthunter_dot_exe("Apollo");
    }

    {
        srand(time(NULL));

        ScavTrap	scav("Scavtrap");
        ScavTrap	sscav("Pepetrap");
        ScavTrap	ssscav(scav);

        ssscav = sscav;

        scav.meleeAttack("Mordecai");
        scav.rangedAttack("Mordecai");
        scav.challengeNewcomer("Mordecai");
        scav.takeDamage(1);
        scav.takeDamage(50);
        scav.takeDamage(50);
        scav.takeDamage(42);
        scav.takeDamage(10);
        scav.challengeNewcomer("Mordecai");
        scav.beRepaired(10);
        scav.beRepaired(20);
        scav.beRepaired(42);
        scav.beRepaired(100500);
        scav.challengeNewcomer("Mordecai");
        scav.challengeNewcomer("Mordecai");
    }
}
