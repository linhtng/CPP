#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << CYAN "Cure's default constructor called\n" RESET;
}

Cure::Cure(const Cure &src)
{
    // std::cout << "Cure's copy constructor called\n";
    *this = src;
}

Cure &Cure::operator=(const Cure &src)
{
    // std::cout << "Cure's copy assignment operator called\n";
    type = "cure";
    if (src.getType() != "cure")
        std::cout << "You are assigning a different type of AMateria to a Cure. Please don't!\n";
    return *this;
}

Cure::~Cure()
{
    // std::cout << RED "Cure destructor called.\n" RESET;
}

AMateria *Cure::clone() const
{
    AMateria *cureDolly = new Cure;
    return cureDolly;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals ";
    std::cout << target.getName();
    std::cout << "'s wounds *\n";
}