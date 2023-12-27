#include "Span.hpp"
#include <cstdlib> // For rand() function
#include <ctime>   // For time() function

void subjectTest()
{
    std::cout << CYAN "Given subject test\n" RESET;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void rangeIteratorTest()
{
    std::cout << CYAN "\nTest the use of range of iterators\n" RESET;
    Span sp = Span(10);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::vector<int> foo;
        for (int i = 1; i <= 5; i++)
            foo.push_back(i * 10);
        sp.addNumbers(foo);
        sp.showContains();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED "Error: " << e.what() << RESET << std::endl;
    }
}

void exceptionTest()
{
    std::cout << CYAN "\nException test\n" RESET;
    Span sp = Span(1);
    try
    {
        sp.addNumber(6);
        // sp.addNumber(3); //uncomment this to get the Out of storage space exception

        sp.showContains();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED "Error: " << e.what() << RESET << std::endl;
    }
}

void largerTest()
{
    std::cout << CYAN "\nTest Span at least with a minimum of 10 000 numbers and more\n" RESET;
    try
    {
        const int numTests = 10; // Perform 10 tests with different numbers of elements

        for (int i = 0; i < numTests; ++i)
        {
            const int numElements = 10000 * (i + 1); // Increase the number of elements for each test

            // Generate a vector of random integers
            std::vector<int> randomNumbers;
            srand(static_cast<unsigned>(time(NULL)));
            for (int j = 0; j < numElements; ++j)
                randomNumbers.push_back(rand() % 2000000);

            Span sp(numElements);

            // Add the random numbers to the Span
            sp.addNumbers(randomNumbers);

            std::cout << "Test " << i + 1 << ":" << std::endl;
            std::cout << "Number of elements: " << numElements << std::endl;
            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
            std::cout << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void copyAssignmentTest()
{
    std::cout << CYAN "\nTest copy assignment operator\n" RESET;
    Span sp(5);
    Span src(6);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.showContains();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::vector<int> foo;
        for (int i = 1; i <= 6; i++)
            foo.push_back(i * 10);
        src.addNumbers(foo);

        sp = src;
        sp.showContains();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED "Error: " << e.what() << RESET << std::endl;
    }
}

int main()
{
    subjectTest();
    rangeIteratorTest();
    exceptionTest();
    largerTest();
    copyAssignmentTest();
    return 0;
}