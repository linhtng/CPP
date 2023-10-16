#include "Fixed.hpp"

/* Public */

Fixed::Fixed() : rawBits(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &rhs) : rawBits(rhs.getRawBits())
{
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        rawBits = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return rawBits;
}

void Fixed::setRawBits(int const raw)
{
    rawBits = raw;
}
