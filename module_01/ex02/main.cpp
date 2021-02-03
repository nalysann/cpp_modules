#include "utils.hpp"
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main() {
    ZombieEvent event1("jumper");
    ZombieEvent event2;

    Zombie zombie1("runner", "Mike");
    Zombie* zombie2 = new Zombie("sleeper", "Kate");
    Zombie* zombie3 = event1.newZombie("John");
    Zombie* zombie4 = event2.newZombie("Mary");

    event1.setZombieType("kicker");
    event2.setZombieType("swimmer");

    Zombie* zombie5 = event1.newZombie("Emily");
    Zombie* zombie6 = event2.newZombie("Mark");

    zombie1.announce();
    zombie2->announce();
    zombie3->announce();
    zombie4->announce();
    zombie5->announce();
    zombie6->announce();

    delete zombie2;
    delete zombie3;
    delete zombie4;
    delete zombie5;
    delete zombie6;

    randomChump();
    randomChump("smasher");
    randomChump("crusher");
}
