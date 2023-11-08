#include "Cat.hpp"

/* Public */

Cat::Cat()
{
    std::cout << "Cat's default constructor called\n";
    type = "Cat";
}

Cat::Cat(const Cat &rhs)
{
    std::cout << "Cat's copy constructor called\n";
    type = rhs.type;
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat's copy assignment operator called\n";
    type = rhs.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called.\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow\n" RESET;
}