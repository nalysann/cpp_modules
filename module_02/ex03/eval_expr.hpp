#ifndef UTILS_HPP
#define UTILS_HPP

#include <cctype>
#include <string>

std::string remove_spaces(const std::string& s) {
    std::string res;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isspace(s[i])) {
            res.push_back(s[i]);
        }
    }
    return res;
}

#endif
