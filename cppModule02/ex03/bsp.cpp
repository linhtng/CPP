#include "Point.hpp"

Fixed calculateTriangleArea(const Point &p1, const Point &p2, const Point &p3)
{
    // Use Fixed arithmetic for the area calculation
    Fixed area = p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY() - p1.getY() * p2.getX() - p2.getY() * p3.getX() - p3.getY() * p1.getX();

    return Fixed(abs(area.getRawBits()));
}

bool bsp(const Point &A, const Point &B, const Point &C, const Point &point)
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

    // std::cout
    //     << "The area of the triangle is: " << triangle << std::endl;
    // std::cout
    //     << "The area of the areaABP is: " << areaABP << std::endl;
    // std::cout
    //     << "The area of the areaBCP is: " << areaBCP << std::endl;
    // std::cout
    //     << "The area of the areaACP is: " << areaACP << std::endl;

    if (areaABP == 0 || areaBCP == 0 || areaACP == 0)
        return false;

    if ((areaABP + areaACP + areaBCP) == triangle)
        return true;

    return false;
}