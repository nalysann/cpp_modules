#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "usage: ./replace filename s1 s2" << std::endl
                  << "    filename - non-empty string, specifying the path to the existing file" << std::endl
                  << "    s1 - non-empty string, which will be replaced in <filename>" << std::endl
                  << "    s2 - non-empty string, to which <s1> will be replaced in <filename>" << std::endl
                  << "As a result, a file <filename.replace> will be created, with "
                  << "each occurrence of <s1> replaced to <s2>." << std::endl;
        return 1;
    } else {
        const std::string filename(argv[1]);
        const std::string new_filename(filename + ".replace");
        const std::string s1(argv[2]);
        const std::string s2(argv[3]);

        if (filename.empty() || s1.empty() || s2.empty()) {
            std::cout << "replace: " << "Arguments must be non-empty strings" << std::endl;
            return 1;
        }

        std::ifstream ifs(filename.c_str());
        if (ifs.fail()) {
            std::cout << "replace: " << filename
                      << ": File couldn't be opened" << std::endl;
            return 1;
        }

        std::ofstream ofs(new_filename.c_str());
        if (ofs.fail()) {
            std::cout << "replace: " << new_filename
                      << ": File couldn't be created" << std::endl;
            return 1;
        }

        std::string line;
        const size_t len = s1.size();
        while (getline(ifs, line)) {
            size_t pos = 0;
            while (true) {
                pos = line.find(s1, pos);
                if (pos != std::string::npos) {
                    line.replace(pos, len, s2);
                    pos += len;
                } else {
                    break;
                }
            }
            ofs << line << std::endl;
        }
    }
}
