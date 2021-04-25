#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <stdexcept>
#include <string>

class Converter {
  public:
    class InvalidLiteralException : public std::exception {};
    class InvalidCharLiteralException : public InvalidLiteralException {};
    class InvalidIntLiteralException : public InvalidLiteralException {};
    class InvalidFloatLiteralException : public InvalidLiteralException {};
    class InvalidDoubleLiteralException : public InvalidLiteralException {};

    Converter();
    explicit Converter(const std::string& s);
    Converter(const Converter& other);
    Converter& operator=(const Converter& other);
    ~Converter();

    std::string asChar() const;
    std::string asInt() const;
    std::string asFloat() const;
    std::string asDouble() const;

  private:
    double _data;
    size_t _dot_pos;
    size_t _precision;
};

#endif
