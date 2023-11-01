#include "Point.hpp"

Fixed calculateTriangleArea(const Point &p1, const Point &p2, const Point &p3)
{
    Fixed area = p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY() - p1.getY() * p2.getX() - p2.getY() * p3.getX() - p3.getY() * p1.getX();
    return Fixed(abs(area.getRawBits()));
}

bool bsp(Point const A, Point const B, Point const C, Point const point)
{
    if (point == A || point == B || point == C)
    {
        std::cout << "Point is a vertex.\n";
        return false;
    }

    Fixed triangle = calculateTriangleArea(A, B, C);
    Fixed areaABP = calculateTriangleArea(A, B, point);
    Fixed areaBCP = calculateTriangleArea(C, B, point);
    Fixed areaACP = calculateTriangleArea(A, C, point);

    if (areaABP == 0 || areaBCP == 0 || areaACP == 0)
    {
        std::cout << "Point is on edge. Don't be like Point, relax!\n";
        return false;
    }

    if ((areaABP + areaACP + areaBCP) == triangle)
        return true;

    return false;
}