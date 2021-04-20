#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

void readFromConsole() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::cout << input << std::endl;
    }
}

void readFromFile(const std::string& filename) {
    struct stat st;

    if (stat(filename.c_str(), &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            std::cerr << "cato9tails: " << filename
                      << ": Is a directory" << std::endl;
            return;
        }
    } else {
        std::cerr << "cato9tails: " << filename
                  << ": No such file or directory" << std::endl;
        return;
    }

    std::ifstream ifs(filename.c_str());

    if (!ifs) {
        std::cerr << "cato9tails: " << filename
                  << ": Permission denied" << std::endl;
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
