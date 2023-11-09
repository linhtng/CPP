#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << CYAN "Cure's default constructor called\n" RESET;
}

Cure::Cure(const Cure &src)
{
    std::cout << "Cure's copy constructor called\n";
}

Cure &Cure::operator=(const Cure &src)
{
    std::cout << "Cure's copy assignment operator called\n";
    return *this;
}

Cure::~Cure()
{
    std::cout << RED "Cure destructor called.\n" RESET;
}

AMateria *Cure::clone() const
{
    AMateria *cureDolly = new Cure;
    return cureDolly;
}