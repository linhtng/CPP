#include "Point.hpp"

Fixed calculateTriangleArea(const Point &p1, const Point &p2, const Point &p3);
bool bsp(Point const A, Point const B, Point const C, Point const point);

int main()
{
    Point p1(-1.0f, 2.0f);
    Point p2(2.0f, 3.0f);
    Point p3(4.0f, -3.0f);

    Point P(-10.0f, -12.0f);

    // Fixed triangle = calculateTriangleArea(p1, p2, p3);

    // std::cout << "The area of the triangle is: " << triangle << std::endl;
    std::cout << "Point is inside the triangle\t: " << std::boolalpha << (bsp(p1, p2, p3, P)) << std::endl;

    return 0;
}
