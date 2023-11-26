#include "Dog.hpp"

/* Public */

Dog::Dog()
{
    std::cout << CYAN "Dog's default constructor called\n" RESET;
    type = "Dog";
    dogBrain = new Brain;
}

Dog::Dog(const Dog &rhs)
{
    std::cout << CYAN "Dog's copy constructor called\n" RESET;
    type = rhs.type;
    dogBrain = new Brain(*rhs.dogBrain);
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << CYAN "Dog's copy assignment operator called\n" RESET;
    type = rhs.type;
    dogBrain = rhs.dogBrain;
    return *this;
}

Dog::~Dog()
{
    delete dogBrain;
    std::cout << RED "Dog destructor called.\n" RESET;
}

void Dog::makeSound() const
{
    std::cout << "Woof\n" RESET;
}

Brain *Dog::getBrain() const
{
    return dogBrain;
}