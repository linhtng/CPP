#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void subjectTest()
{
    std::cout << "Subject Test\n";
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete[] mirror;
            return;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand();

    delete[] mirror;
}

void basicTest()
{
    std::cout << "\nBasic Test\n";

    // Test construction with an unsigned int n as a parameter
    Array<int> arr1(5); // Create an array with 5 elements

    // Test copy constructor
    Array<int> arr2(arr1); // Copy arr1 to arr2

    // Test create an empty array & assignment operator
    Array<int> arr3;
    arr3 = arr1;

    // Modify arr1 and arr2. The change won't affect the other arrays.
    try
    {
        arr1[0] = 42;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        arr2[0] = 21;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // Display array contents
    std::cout << "arr1: ";
    for (size_t i = 0; i < arr1.size(); ++i)
        std::cout << arr1[i] << " ";

    std::cout << "\narr2: ";
    for (size_t i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";

    std::cout << "\narr3: ";
    for (size_t i = 0; i < arr3.size(); ++i)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;
}

void constInstanceTest()
{
    std::cout << "\nConst Instance Test\n";
    const Array<int> const_numbers(1);
    std::cout << const_numbers[0] << std::endl;

    // Attempt to modify elements (should result in a compilation error)
    /*  try
     {
         const_numbers[0] = 42;
     }
     catch (const std::exception &e)
     {
         std::cerr << e.what() << '\n';
     } */
}

void strArrayTest()
{
    std::cout << "\nstrArrayTest\n";
    Array<std::string> strArray(2);
    std::cout << strArray[0] << std::endl;
    std::cout << strArray[1] << std::endl;

    strArray[0] = "hi!\n";
    std::cout << strArray[0];
}

// Hypothetical ComplexNumber class for testing
class ComplexNumber
{
public:
    ComplexNumber() : x(0.0), y(0.0) {}
    ComplexNumber(double x, double y) : x(x), y(y) {}

    // Getter functions
    double getX() const { return x; }
    double getY() const { return y; }

private:
    double x;
    double y;
};

void complexTypeTest()
{
    std::cout << "\nArray test with more complex type\n";
    // Create an array of ComplexNumber objects
    Array<ComplexNumber> complexArray(3);
    complexArray[0] = ComplexNumber(1.0, 2.0);
    complexArray[1] = ComplexNumber(-3.0, 4.0);
    complexArray[2] = ComplexNumber(0.5, -1.5);

    // Display the elements of the complex array
    std::cout << "Complex Array: ";
    for (unsigned int i = 0; i < complexArray.size(); ++i)
    {
        std::cout << "(" << complexArray[i].getX() << ", " << complexArray[i].getY() << ") ";
    }
    std::cout << std::endl;
}

int main(int, char **)
{
    subjectTest();

    basicTest();

    constInstanceTest();

    strArrayTest();

    complexTypeTest();

    return 0;
}