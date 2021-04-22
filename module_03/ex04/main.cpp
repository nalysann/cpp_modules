#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "SuperTrap.hpp"

int main() {
    {
        srand(time(NULL));

        ClapTrap clap("Claptrap");
        ClapTrap cclap("Pepetrap");
        ClapTrap ccclap(clap);

        ccclap = cclap;

        clap.takeDamage(40);
        clap.takeDamage(1);
        clap.takeDamage(100);
        clap.takeDamage(22);
        clap.beRepaired(20);
        clap.beRepaired(777);
    }

    std::cout << std::endl;

    {
        srand(time(NULL));

        FragTrap frag("Fragtrap");
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

    std::cout << std::endl;

    {
        srand(time(NULL));

        ScavTrap scav("Scavtrap");
        ScavTrap sscav("Pepetrap");
        ScavTrap ssscav(scav);

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

    std::cout << std::endl;
    
    {
        srand(time(NULL));

        ClapTrap clap("Claptrap");
        FragTrap frag("Fragtrap");
        ScavTrap scav("Scavtrap");
        
        NinjaTrap ninja("Ninjatrap");
        NinjaTrap nninja("Pepetrap");
        NinjaTrap nnninja(ninja);

        nnninja = nninja;

        ninja.meleeAttack("Handsome Jack");
        ninja.rangedAttack("Handsome Jack");
        ninja.takeDamage(5);
        ninja.takeDamage(50);
        ninja.takeDamage(50);
        ninja.takeDamage(10);
        ninja.beRepaired(50);
        ninja.beRepaired(70);
        ninja.ninjaShoebox(clap);
        ninja.ninjaShoebox(frag);
        ninja.ninjaShoebox(scav);
        ninja.ninjaShoebox(nninja);
    }

    std::cout << std::endl;

    {
        srand(time(NULL));

        ClapTrap clap("Claptrap");
        
        SuperTrap super("Supertrap");
        SuperTrap ssuper("Pepetrap");
        SuperTrap sssuper(super);
        
        sssuper = ssuper;

        super.meleeAttack("Roland");
        super.rangedAttack("Roland");
        super.takeDamage(50);
        super.takeDamage(5);
        super.takeDamage(50);
        super.takeDamage(33);
        super.takeDamage(10);
        super.beRepaired(20);
        super.beRepaired(50);
        super.beRepaired(70);
        super.ninjaShoebox(clap);
        super.vaulthunter_dot_exe("Roland");
    }
}
