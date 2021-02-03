#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

void readFromConsole() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::cout << input << std::endl;
    }
}

void readFromFile(const std::string& filename) {
    std::ifstream ifs(filename.c_str());

    if (ifs.fail()) {
        std::cout << "cato9tails: " << filename
                  << ": Can't open file" << std::endl;
        return;
    }

    std::string input;
    while (std::getline(ifs, input)) {
        std::cout << input << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        readFromConsole();
    } else {
        for (int i = 1; i < argc; ++i) {
            std::string filename(argv[i]);
            if (filename == "-") {
                std::cin.clear();
                rewind(stdin);
                readFromConsole();
            } else {
                readFromFile(filename);
            }
        }
    }
}
