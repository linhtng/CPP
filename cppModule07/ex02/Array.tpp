#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(new T[0]), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), length(n)
{
    for (unsigned int i = 0; i < length; ++i)
        data[i] = T();
}

template <typename T>
Array<T>::Array(const Array &src) : length(src.size())
{
    data = new T[length];
    for (unsigned int i = 0; i < length; ++i)
        data[i] = src.data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    delete[] data; // Release existing memory
    length = src.size();
    data = new T[length];
    for (unsigned int i = 0; i < length; ++i)
        data[i] = src.data[i];
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= length)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= length)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return length;
}