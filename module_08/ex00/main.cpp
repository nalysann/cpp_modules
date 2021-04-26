#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
    {
        std::vector<int> v;

        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        v.push_back(7);
        v.push_back(11);
        v.push_back(13);

        for (int i = 4; i < 12; ++i) {
            std::cout << "Value " << i
                      << (easyfind(v, i) != v.end() ? " found in vector!" : " not found in vector :(")
                      << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::list<int> v;

        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        v.push_back(7);
        v.push_back(11);
        v.push_back(13);

        for (int i = 4; i < 12; ++i) {
            std::cout << "Value " << i
                      << (easyfind(v, i) != v.end() ? " found in list!" : " not found in list :(")
                      << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::deque<int> v;

        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        v.push_back(7);
        v.push_back(11);
        v.push_back(13);

        for (int i = 4; i < 12; ++i) {
            std::cout << "Value " << i
                      << (easyfind(v, i) != v.end() ? " found in deque!" : " not found in deque :(")
                      << std::endl;
        }
    }
}