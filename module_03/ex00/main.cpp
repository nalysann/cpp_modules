#include <cstdlib>
#include <ctime>

#include "FragTrap.hpp"

int main() {
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
