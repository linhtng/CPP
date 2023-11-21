#include "AMateria.hpp"

/* Public */

AMateria::AMateria()
{
    // std::cout << CYAN "AMateria's default constructor called\n" RESET;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    // std::cout << CYAN "AMateria's parameter constructor called\n" RESET;
}

AMateria::AMateria(const AMateria &src)
{
    // std::cout << "AMateria's copy constructor called\n";
    *this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    // std::cout << "AMateria's copy assignment operator called\n";
    return *this;
}

AMateria::~AMateria()
{
    // std::cout << RED "AMateria destructor called.\n" RESET;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria use(less) function is called.\n";
}