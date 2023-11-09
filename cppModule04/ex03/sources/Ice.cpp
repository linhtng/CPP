#include "Ice.hpp"

/* Public */

Ice::Ice() : AMateria("ice")
{
    std::cout << CYAN "Ice's default constructor called\n" RESET;
}

Ice::Ice(const Ice &src)
{
    std::cout << "Ice's copy constructor called\n";
}

Ice &Ice::operator=(const Ice &src)
{
    std::cout << "Ice's copy assignment operator called\n";
    return *this;
}

Ice::~Ice()
{
    std::cout << RED "Ice destructor called.\n" RESET;
}

AMateria *Ice::clone() const
{
    AMateria *iceDolly = new Ice;
    return iceDolly;
}