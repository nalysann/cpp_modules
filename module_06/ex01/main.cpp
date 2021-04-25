#include <iostream>
#include <string>

#include "Data.hpp"

void* serialize() {
    static const std::string alphanumeric = "0123456789"
                                            "ABCDEFGHIJKLMOPQRSTUVXYZ"
                                            "abcdefghijklmopqrstuvxyz";

    char* raw = new char[20];

    for (int i = 0; i < 8; ++i) {
        raw[i] = alphanumeric[rand() % alphanumeric.size()];
        std::cout << raw[i];
    }

    int n = rand();
    std::cout << ' ' << n << ' ';
    *reinterpret_cast<int*>(raw + 8) = n;

    for (int i = 12; i < 20; ++i) {
        raw[i] = alphanumeric[rand() % alphanumeric.size()];
        std::cout << raw[i];
    }

    std::cout << std::endl;

    return raw;
}

Data* deserialize(void* raw) {
    Data* data = new Data;

    data->s1 = std::string(reinterpret_cast<char*>(raw), 8);
    data->n = *reinterpret_cast<int*>(reinterpret_cast<char*>(raw) + 8);
    data->s2 = std::string(reinterpret_cast<char*>(raw) + 12, 8);

    return data;
}

int main() {
    srand(time(NULL));

    void* raw = serialize();
    Data* data = deserialize(raw);

    std::cout << data->s1 << ' ' << data->n << ' ' << data->s2 << std::endl;

    delete[] reinterpret_cast<char*>(raw);
    delete data;
}
