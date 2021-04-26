#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include <stdexcept>

template<class T>
class Array {
  public:
    Array<T>()
            : _size(0)
            , _data(NULL) {}

    explicit Array<T>(unsigned n)
            : _size(n)
            , _data(new T[n]) {}

    Array<T>(const Array<T>& other)
            : _size(other._size)
            , _data(new T[other.size()]) {
        for (unsigned i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this == &other) {
            return *this;
        }

        delete[] _data;

        _size = other._size;
        _data = new T[other._size];

        for (unsigned i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }

        return *this;
    }

    ~Array<T>() {
        delete[] _data;
    }

    T& operator[](unsigned idx) {
        if (idx >= _size) {
            throw std::exception();
        }
        return _data[idx];
    }

    const T& operator[](unsigned idx) const {
        if (idx >= _size) {
            throw std::exception();
        }
        return _data[idx];
    }

    unsigned size() const {
        return _size;
    }

  private:
    unsigned _size;
    T* _data;
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
    os << '[';
    for (unsigned i = 0; i < array.size(); ++i) {
        if (i != 0) {
            os << ", ";
        }
        os << array[i];
    }
    os << ']';
    return os;
}

#endif
