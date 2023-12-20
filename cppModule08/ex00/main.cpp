#include <iostream>
#include <iterator>
#include "easyfind.hpp"
#include <list>

#define RED "\e[91m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

void testVectorType()
{
    try
    {
        std::cout << CYAN "Test with vector container\n" RESET;
        std::vector<int> vec;
        int val = 0;
        // Print out the vector
        std::cout << "vec: \n";
        for (int i = 0; i < 5; ++i)
        {
            vec.push_back(val++);
            std::cout << vec[i] << " ";
        }
        std::cout << '\n';

        int searchValue = 1;

        std::vector<int>::iterator vecResult = easyfind(vec, searchValue);
        std::cout << "Value " << searchValue << " found in vec at position: " << std::distance(vec.begin(), vecResult) << std::endl;

        // Trying to find a value not present in the containers
        int notPresentValue = 99;
        std::vector<int>::iterator result = easyfind(vec, notPresentValue); // This will throw an exception
        std::cout << "Value " << searchValue << " found in vec at position: " << std::distance(vec.begin(), result) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

void testListType()
{
    try
    {
        std::cout << CYAN "\nTest with list container\n" RESET;

        std::list<int> lst;
        int val = 10;
        // Print out the vector
        for (int i = 0; i < 5; ++i)
            lst.push_back(val++);

        std::cout << "lst: \n";
        for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
            std::cout << *i << "    ";
        std::cout << '\n';

        int searchValue = 10;

        std::list<int>::iterator lstResult = easyfind(lst, searchValue);
        std::cout << "Value " << searchValue << " found in lst at position: " << std::distance(lst.begin(), lstResult) << std::endl;

        // Trying to find a value not present in the containers
        int notPresentValue = 99;
        std::list<int>::iterator errLstResult = easyfind(lst, notPresentValue); // This will throw an exception
        std::cout << "Value " << notPresentValue << " found in lst at position: " << std::distance(lst.begin(), errLstResult) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

int main()
{
    testVectorType();

    testListType();

    return 0;
}