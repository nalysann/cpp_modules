#include <cctype>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; ++i) {
            for (char* str = argv[i]; *str != '\0'; ++str) {
                std::cout << static_cast<char>(toupper(*str));
            }
        }
        std::cout << std::endl;
    }
}
