#include "Dog.hpp"

/* Public */

Dog::Dog()
{
    std::cout << "Dog's default constructor called\n";
    type = "Dog";
}

Dog::Dog(const Dog &rhs)
{
    std::cout << "Dog's copy constructor called\n";
    type = rhs.type;
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog's copy assignment operator called\n";
    type = rhs.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called.\n";
}

void Dog::makeSound() const
{
    std::cout << "Woof\n" RESET;
}