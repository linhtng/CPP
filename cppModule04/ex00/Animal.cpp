#include "Animal.hpp"

/* Public */

Animal::Animal()
{
    std::cout << "Animal's default constructor called\n";
}

Animal::Animal(const Animal &rhs)
{
    std::cout << "Animal's copy constructor called\n";
    type = rhs.type;
}

Animal &Animal::operator=(const Animal &rhs)
{
    std::cout << "Animal's copy assignment operator called\n";
    type = rhs.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called.\n";
}

void Animal::makeSound() const
{
    std::cout << "???\n" RESET;
}

std::string Animal::getType() const
{
    return type;
}