#include "Fixed.hpp"

/* Public */
Fixed::Fixed() : rawBits(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const integer) : rawBits(integer << fractionalBits)
{
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const floatNumber) : rawBits(std::roundf(floatNumber * (1 << fractionalBits)))
{
    std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called\n";
    rawBits = rhs.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        rawBits = rhs.rawBits;
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

float Fixed::toFloat() const
{
    return static_cast<float>(rawBits) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return rawBits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &outputStream, Fixed const &rhs)
{
    outputStream << rhs.toFloat();
    return outputStream;
}