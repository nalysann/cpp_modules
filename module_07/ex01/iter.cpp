#include <iostream>
#include <string>

#include "Awesome.hpp"

template<class T>
void print(const T& value) {
    std::cout << value << std::endl;
}

template<class T>
void iter(const T* array, size_t length, void (*fun)(const T&)) {
    for (size_t i = 0; i < length; ++i) {
        fun(array[i]);
    }
}

int main() {
    int int_array[] = {2, 3, 5, 7, 11, 13};
    std::string str_array[] = {"potato", "tomato", "apple", "banana"};
    Awesome awesome_array[5];

    iter(int_array, 6, print);

    std::cout << std::endl;

    iter(str_array, 4, print);

    std::cout << std::endl;

    iter(awesome_array, 5, print);
}
