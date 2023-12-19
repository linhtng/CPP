#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Function template to swap two values
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Function template to find the minimum of two values
template <typename T>
T min(const T &a, const T &b)
{
    return (b < a) ? b : a;
}

// Function template to find the maximum of two values
template <typename T>
T max(const T &a, const T &b)
{
    return (a < b) ? b : a;
}

#endif