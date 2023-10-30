#include "Point.hpp"

/* Constructors */

Point::Point() : x(0), y(0) {}

Point::Point(float const floatX, float const floatY) : x(floatX), y(floatY) {}

Point::Point(const Point &rhs)
{
    *this = rhs;
}

Point &Point::operator=(const Point &rhs)
{
    if (this == &rhs)
        std::cerr << "Warning: assigning an instance to itself!\n";
    return *this;
}

/* Destructor */

Point::~Point()
{
    // std::cout << "Destructor called\n";
}

/* CLASS PUBLIC METHODS */

Fixed const Point::getX() const
{
    return x;
}

Fixed const Point::getY() const
{
    return y;
}

bool Point::operator==(const Point &rhs) const
{
    if (this->getX() == rhs.getX() && this->getY() == rhs.getY())
    {
        // std::cout << "lhs x: " << this->getX() << '\n';
        // std::cout << "lhs y: " << this->getY() << '\n';
        // std::cout << "rhs x: " << rhs.getX() << '\n';
        // std::cout << "rhs y: " << rhs.getY() << '\n';
        return true;
    }
    return false;
}
