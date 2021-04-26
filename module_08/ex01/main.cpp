#include <iostream>
#include <stdexcept>
#include <vector>

#include "span.hpp"

int main() {
    {
        Span sp = Span(5);

        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::logic_error& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::logic_error& e) {
            std::cout << e.what() << std::endl;
        }

        sp.addNumber(5);

        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::logic_error& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::logic_error& e) {
            std::cout << e.what() << std::endl;
        }

        sp.addNumber(3);

        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::logic_error& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::logic_error& e) {
            std::cout << e.what() << std::endl;
        }

        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        try {
            sp.addNumber(8);
        } catch (std::length_error& e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << std::endl;

    {
        std::vector<int> v(100000);

        for (int i = 0; i < static_cast<int>(v.size()); ++i) {
            v[i] = 2 * i + 1;
        }

        Span sp(v.size());

        sp.addRange(v.begin(), v.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        try {
            sp.addNumber(42);
        } catch (std::length_error& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            sp.addRange(v.begin(), v.end());
        } catch (std::length_error& e) {
            std::cout << e.what() << std::endl;
        }
    }
}
