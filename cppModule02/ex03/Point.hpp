#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
public:
    Point();
    Point(float const floatX, float const floatY);
    Point(Point const &rhs);
    Point &operator=(const Point &rhs);
    ~Point();

    Fixed const getX() const;
    Fixed const getY() const;
    bool operator==(const Point &rhs) const;

private:
    Fixed const x;
    Fixed const y;
};

#endif
