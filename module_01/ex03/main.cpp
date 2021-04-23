#include <cstdlib>
#include <ctime>

#include "ZombieHorde.hpp"

int main() {
    srand(time(NULL));

    ZombieHorde horde1;
    ZombieHorde horde2(21);

    horde1.announce();
    horde2.announce();
}
