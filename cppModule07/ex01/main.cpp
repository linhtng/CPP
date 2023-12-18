#include "iter.hpp"

// Example function template to be used with iter
template <typename T>
void printElement(const T &element)
{
    std::cout << element << "   ";
}

void integerArray()
{
    // Test with an integer array
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "Iterating over the integer array: \n";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;
}

void doubleArray()
{
    // Test with a double array
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

    std::cout << "Iterating over the double array: \n";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;
}

void stringArray()
{
    // Test with a string array
    std::string stringArray[] = {"apple", "orange", "banana", "grape", "kiwi"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(std::string);

    std::cout << "Iterating over the string array: \n";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;
}

int main()
{
    integerArray();
    doubleArray();
    stringArray();

    return 0;
}