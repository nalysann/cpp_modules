#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <set>
#include <string>
#include <stdexcept>

class Span {
  public:
    explicit Span(unsigned n = 0);
    Span(const Span& other);
    Span& operator=(const Span&);
    ~Span();

    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;

    template<class InputIt>
    void addRange(InputIt first, InputIt last) {
        while (first != last) {
            addNumber(*first++);
        }
    }

  private:
    const unsigned _size;
    std::set<int> _data;
};

#endif
