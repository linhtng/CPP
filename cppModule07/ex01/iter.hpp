#pragma once
#include <iostream>

/* Function template iter that takes 3 parameters
1. The address of an array.
2. The length of the array.
3. The function that will be called on every element of the array. */
template <typename T, typename F>
void iter(T *array, size_t length, F function)
{
    for (size_t i = 0; i < length; ++i)
        function(array[i]);
}