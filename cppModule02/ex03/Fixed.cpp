#include "Fixed.hpp"

/* Constructors */

Fixed::Fixed() : rawBits(0)
{
    // std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const integer) : rawBits(integer << fractionalBits)
{
    // std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const floatNumber) : rawBits(std::roundf(floatNumber * (1 << fractionalBits)))
{
    // std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &rhs)
{
    // std::cout << "Copy constructor called\n";
    *this = rhs;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    // std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return *this;
}

/* The 6 comparison operators: >, <, >=, <=, == and != */

bool Fixed::operator>(const Fixed &rhs) const
{
    return (rawBits > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (rawBits < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (rawBits >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (rawBits <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (rawBits == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (rawBits != rhs.getRawBits());
}

/* The 4 arithmetic operators: +, -, *, and / */

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed res;
    res.setRawBits(this->getRawBits() + rhs.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed res;
    res.setRawBits(this->getRawBits() - rhs.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed res;
    res.rawBits = (static_cast<int64_t>(rawBits) * static_cast<int64_t>(rhs.rawBits)) >> fractionalBits;
    return res;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed res;
    res.rawBits = static_cast<int64_t>(rawBits) * (1 << fractionalBits) / static_cast<int64_t>(rhs.rawBits);
    return res;
}

/* The 4 increment/decrement (pre- & post-increment, pre- & post-decrement) operators */

Fixed &Fixed::operator++()
{
    rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed original(*this);
    ++(*this);
    return original;
}

Fixed &Fixed::operator--()
{
    rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed original(*this);
    --(*this);
    return original;
}

/* Destructor */

Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
}

/* CLASS STATIC MEMBER FUNCTIONS */

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

// Static member function to find the maximum of two fixed-point numbers
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

// Static member function to find the maximum of two constant fixed-point numbers
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

/* CLASS PUBLIC METHODS */

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called\n";
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

/* Output Stream */

std::ostream &operator<<(std::ostream &outputStream, const Fixed &rhs)
{
    outputStream << rhs.toFloat();
    return outputStream;
}
