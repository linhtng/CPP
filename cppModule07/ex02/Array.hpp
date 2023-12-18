#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    T *data;
    unsigned int length;

public:
    Array();
    Array(unsigned int length);
    Array(const Array &src);
    Array &operator=(const Array &src);
    ~Array();

    unsigned int size() const;
    T &operator[](unsigned int index);
};

#include "Array.tpp" // Include the implementation file