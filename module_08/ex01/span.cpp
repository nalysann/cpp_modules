#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

#include "span.hpp"

Span::Span(unsigned n)
        : _size(n) {}

Span::Span(const Span& other)
        : _size(other._size)
        , _data(other._data) {
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_data.size() == _size) {
        throw std::length_error("Span is full");
    }

    _data.insert(n);
}

int Span::shortestSpan() const {
    if (_data.size() < 2) {
        throw std::logic_error("Span doesn't have enough elements");
    }

    std::vector<int> adjacent_diffs(_data.size());
    std::adjacent_difference(_data.begin(), _data.end(), adjacent_diffs.begin());

    return *std::min_element(++(adjacent_diffs.begin()), adjacent_diffs.end());
}

int Span::longestSpan() const {
    if (_data.size() < 2) {
        throw std::logic_error("Span doesn't have enough elements");
    }

    return *_data.crbegin() - *_data.begin();
}
