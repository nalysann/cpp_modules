#include <iostream>

#include "Fixed.hpp"

int main() {
    Fixed a;
    const Fixed b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << std::boolalpha;
    std::cout << (a > b) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a >= b) << std::endl;
    std::cout << (a <= b) << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;
    std::cout << std::noboolalpha;

    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;

    std::cout << max(a, b) << std::endl;
    std::cout << min(a, b) << std::endl;
}
