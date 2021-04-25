#include <iostream>

#include "Converter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./convert literal_value" << std::endl
                  << "where <literal_value> is either char, int, float" << std::endl
                  << "or double literal, represented as a string" << std::endl;
        return 1;
    }

    try {
        Converter conv(argv[1]);

        std::cout << conv.asChar() << std::endl;
        std::cout << conv.asInt() << std::endl;
        std::cout << conv.asFloat() << std::endl;
        std::cout << conv.asDouble() << std::endl;
    } catch (Converter::InvalidCharLiteralException& e) {
        std::cerr << "Bad char literal" << std::endl;
    } catch (Converter::InvalidIntLiteralException& e) {
        std::cerr << "Bad int literal" << std::endl;
    } catch (Converter::InvalidFloatLiteralException& e) {
        std::cerr << "Bad float literal" << std::endl;
    } catch (Converter::InvalidDoubleLiteralException& e) {
        std::cerr << "Bad double literal" << std::endl;
    } catch (Converter::InvalidLiteralException& e) {
        std::cerr << "Bad literal" << std::endl;
    }
}