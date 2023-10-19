#include "Point.hpp"

Fixed calculateTriangleArea(const Point &p1, const Point &p2, const Point &p3)
{
    // Use Fixed arithmetic for the area calculation
    Fixed area = (p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY() - p1.getY() * p2.getX() - p2.getY() * p3.getX() - p3.getY() * p1.getX()) / Fixed(2);

    return Fixed(abs(area.toFloat()));
}

bool bsp(Point const A, Point const B, Point const C, Point const point)
{
    // if (point == A || point == B || point == C)
    // {
    //     std::cout << "Point is a vertex.\n";
    //     return false;
    // }

    Fixed triangle = calculateTriangleArea(A, B, C);
    Fixed areaABP = calculateTriangleArea(A, B, point);
    Fixed areaBCP = calculateTriangleArea(C, B, point);
    Fixed areaACP = calculateTriangleArea(A, C, point);

    std::cout
        << "The area of the triangle is: " << triangle << std::endl;

    if (areaABP == 0 || areaBCP == 0 || areaACP == 0)
        return false;

    if ((areaABP + areaACP + areaBCP) == triangle)
        return true;

    if (point == A || point == B || point == C)
    {
        std::cout << "Point is a vertex.\n";
        return false;
    }

    return false;
}