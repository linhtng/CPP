#include "WrongAnimal.hpp"

/* Public */

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal's default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal's copy constructor called\n";
    type = rhs.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal's copy assignment operator called\n";
    type = rhs.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called.\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << "????\n" RESET;
}

std::string WrongAnimal::getType() const
{
    return type;
}