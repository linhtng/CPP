#include "Cat.hpp"

/* Public */

Cat::Cat()
{
    std::cout << CYAN "Cat's default constructor called\n" RESET;
    type = "Cat";
    catBrain = new Brain;
}

Cat::Cat(const Cat &rhs)
{
    std::cout << CYAN "Cat's copy constructor called\n" RESET;
    type = rhs.type;
    catBrain = new Brain(*rhs.catBrain);
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << CYAN "Cat's copy assignment operator called\n" RESET;
    type = rhs.type;
    catBrain = new Brain(*rhs.catBrain);
    return *this;
}

Cat::~Cat()
{
    delete catBrain;
    std::cout << RED "Cat destructor called.\n" RESET;
}

void Cat::makeSound() const
{
    std::cout << "Meow\n" RESET;
}

Brain *Cat::getBrain() const
{
    return catBrain;
}