#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    Array();
    explicit Array(unsigned int n);
    Array(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);
    ~Array();
    
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};

#include "Array.tpp"

#endif
