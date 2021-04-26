#include <iostream>
#include <string>

#include "Awesome.hpp"

template<class T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
const T& min(const T& a, const T& b) {
    return a < b ? a : b;
}

template<class T>
const T& max(const T& a, const T& b) {
    return a > b ? a : b;
}

int	main() {
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    Awesome x(42);
    Awesome y(100500);

    ::swap(x, y);
    std::cout << "x = " << x << ", x = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
}
