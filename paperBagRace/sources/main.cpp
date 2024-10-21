
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding the random number generator
#include <iostream>
#include <exception>

#include "Base.hpp"

#define RESET "\e[0m"
#define RED "\e[91m"

Base *generate()
{
    int randomNumber = rand() % 3;

    switch (randomNumber)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return NULL;
    }
}

void identify(Base *p)
{
    std::cout << "ID using pointer: \n";
    if (dynamic_cast<A *>(p))
    {
        // Object is of type A
        std::cout << "type A\n";
    }
    else if (dynamic_cast<B *>(p))
    {
        // Object is of type B
        std::cout << "type B\n";
    }
    else if (dynamic_cast<C *>(p))
    {
        // Object is of type C
        std::cout << "type C\n";
    }
    else
        std::cout << "type undefined\n";
}

void identify(Base &p)
{
    std::cout << "ID using reference: \n";
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "type A\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "type B\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "type C\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

int main()
{
    // Seed the random number generator
    std::srand(std::time(NULL));

    // Generate a random object
    Base *randomObject = generate();

    // Identify the object using a pointer
    identify(randomObject);
    std::cout << std::endl;

    // Identify the object using a reference
    identify(*randomObject);
    std::cout << std::endl;

    // Clean up memory
    delete randomObject;

    return 0;
}