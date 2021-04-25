#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

#include "Converter.hpp"

Converter::Converter(const std::string& s)
        : _dot_pos(s.find('.'))
        , _precision(1) {
    if (s.size() == 1 && !isdigit(s.front())) {
        if (isprint(s.front())) {
            _data = static_cast<int>(s.front());
            return;
        } else {
            throw InvalidCharLiteralException();
        }
    } else if (s.empty() || isspace(s.front())) {
        throw InvalidLiteralException();
    } else {
        char* endptr;

        errno = 0;
        long long ll_data = strtoll(s.c_str(), &endptr, 10);
        if (*endptr == '\0') {
            if (errno != 0 ||
                ll_data < std::numeric_limits<int>::min() ||
                ll_data > std::numeric_limits<int>::max()) {
                throw InvalidIntLiteralException();
            }
            _data = static_cast<int>(ll_data);
            return;
        }

        errno = 0;
        float float_data = strtof(s.c_str(), &endptr);
        if (s == "-inff" || s == "+inff" || s == "inff" || s == "nanf" ||
            (_dot_pos != std::string::npos && endptr[0] == 'f' && endptr[1] == '\0')) {
            if (errno != 0) {
                throw InvalidFloatLiteralException();
            }
            _data = float_data;
            if (_dot_pos != std::string::npos && _dot_pos + 2 != s.size()) {
                _precision = s.size() - _dot_pos - 2;
            }
            return;
        }

        errno = 0;
        double double_data = strtod(s.c_str(), &endptr);
        if (*endptr == '\0') {
            if (errno != 0) {
                throw InvalidDoubleLiteralException();
            }
            _data = double_data;
            if (_dot_pos != std::string::npos && _dot_pos + 1 != s.size()) {
                _precision = s.size() - _dot_pos - 1;
            }
            return;
        }

        throw InvalidLiteralException();
    }
}

Converter::~Converter() {}

std::string Converter::asChar() const {
    std::ostringstream oss;

    oss << "char: ";

    int int_data = static_cast<int>(_data);

    if (isnan(_data) || _data < std::numeric_limits<char>::min() ||
                        _data > std::numeric_limits<char>::max()) {
        oss << "impossible";
    } else if (isprint(int_data)) {
        oss << '\'' << static_cast<char>(int_data) << '\'';
    } else {
        oss << "Non displayable";
    }

    return oss.str();
}

std::string Converter::asInt() const {
    std::ostringstream oss;

    oss << "int: ";

    if (isnan(_data) || _data < std::numeric_limits<int>::min() ||
                        _data > std::numeric_limits<int>::max()) {
        oss << "impossible";
    } else {
        oss << static_cast<int>(_data);
    }

    return oss.str();
}

std::string Converter::asFloat() const {
    std::ostringstream oss;

    oss << "float: ";

    if (!isnan(_data) && !isinf(_data) && (_data < std::numeric_limits<float>::lowest() ||
                                           _data > std::numeric_limits<float>::max())) {
        oss << "impossible";
    } else {
        oss << std::fixed << std::setprecision(static_cast<int>(_precision))
            << std::showpoint
            << static_cast<float>(_data)
            << std::noshowpoint;
    }

    oss << 'f';

    return oss.str();
}

std::string Converter::asDouble() const {
    std::ostringstream oss;

    oss << "double: ";

    oss << std::fixed << std::setprecision(static_cast<int>(_precision))
        << std::showpoint
        <<_data
        << std::noshowpoint;

    return oss.str();
}
