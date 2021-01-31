#include "Pony.hpp"

int main() {
    Pony::print_pony_population();
    ponyOnTheStack("Fluttershy");
    Pony::print_pony_population();
    ponyOnTheHeap("Twilight Sparkle");
    Pony::print_pony_population();
}