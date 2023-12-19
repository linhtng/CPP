#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

#define CYAN "\033[36m"
#define RESET "\e[0m"

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
    const T &operator[](unsigned int index) const;
};

#include "Array.tpp" // Include the implementation file

#endif