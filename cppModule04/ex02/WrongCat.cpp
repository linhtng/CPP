#include "WrongCat.hpp"

/* Public */

WrongCat::WrongCat()
{
    std::cout << "WrongCat's default constructor called\n";
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &rhs)
{
    std::cout << "WrongCat's copy constructor called\n";
    type = rhs.type;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    std::cout << "WrongCat's copy assignment operator called\n";
    type = rhs.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called.\n";
}

void WrongCat::makeSound() const
{
    std::cout << "Meowrong\n" RESET;
}