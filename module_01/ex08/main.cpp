#include "Human.hpp"

int main() {
    Human conan("Conan the Barbarian");

    conan.action("melee", "ogre");
    conan.action("scratch", "nose");
    conan.action("ranged", "shadow");
    conan.action("shout", "rats");
    conan.action("cook", "dinner");
    conan.action("sleep", "bed");
}
