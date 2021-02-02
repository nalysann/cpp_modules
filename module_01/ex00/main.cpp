#include "Pony.hpp"

int main() {
    Pony::printPonyPopulation();
    ponyOnTheStack("Fluttershy");
    Pony::printPonyPopulation();
    ponyOnTheHeap("Twilight Sparkle");
    Pony::printPonyPopulation();
}