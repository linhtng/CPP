#include "Point.hpp"

/* Constructors */

Point::Point() : x(0), y(0) {}

Point::Point(float const floatX, float const floatY) : x(floatX), y(floatY) {}

Point::Point(const Point &rhs) : x(rhs.getX()), y(rhs.getY()) {}

Point &Point::operator=(const Point &rhs)
{
    if (this == &rhs)
        std::cerr << "Warning: assigning an instance to itself!\n";
    return *this;
}

/* Destructor */

Point::~Point() {}

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
        return true;
    return false;
}
