#include <iostream>

#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Warrior.hpp"

int main() {
    {
        Sorcerer robert("Robert", "the Magnificent");

        Victim jim("Jimmy");
        Peon joe("Joe");

        std::cout << robert << jim << joe;

        robert.polymorph(jim);
        robert.polymorph(joe);
    }

    std::cout << std::endl;

    {
        Sorcerer medivh("Medivh", "Guardian of Tirisfal");
        Warrior grunt("Smorc");

        std::cout << medivh << grunt;
        medivh.polymorph(grunt);
    }
}
