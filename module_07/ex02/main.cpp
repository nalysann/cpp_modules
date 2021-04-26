#include <iostream>
#include <string>

#include "Array.tpp"

int main() {
    Array<int> int_array(5);
    Array<std::string> string_array(5);
    Array<double> double_array(5);

    for (unsigned i = 0; i < 5; ++i) {
        int_array[i] = 42;
        string_array[i] = "abacaba";
        double_array[i] = 42.21;
    }

    std::cout << "int: " << int_array << std::endl;
    std::cout << "str: " << string_array << std::endl;
    std::cout << "double: " << double_array << std::endl;
    std::cout << std::endl;

    Array<std::string> string_array_copy(string_array);
    std::cout << "str copy: " << string_array_copy << std::endl;
    std::cout << std::endl;

    Array<int> new_int_array(2);
    new_int_array[0] = 42;
    new_int_array[1] = 21;
    std::cout << "int new: " << new_int_array << std::endl;
    std::cout << std::endl;

    std::cout << "int old: " << int_array << std::endl;
    int_array = new_int_array;
    std::cout << "int old: " << int_array << std::endl;
    std::cout << std::endl;

    const Array<int> const_int_array(3);
    std::cout << "const int: " << const_int_array << std::endl;
    std::cout << "element access: " << const_int_array[1] << std::endl;
    std::cout << std::endl;

    try {
        const_int_array[3];
    } catch (std::exception&) {
        std::cout << "Bad index exception caught!" << std::endl;
    }
}
