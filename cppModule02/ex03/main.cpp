#include "Point.hpp"

Fixed calculateTriangleArea(const Point &p1, const Point &p2, const Point &p3);
bool bsp(Point const &A, Point const &B, Point const &C, Point const &point);

int main()
{
    // Point p1(-1.0f, 2.0f);
    // Point p2(2.0f, 3.0f);
    // Point p3(4.0f, -3.0f);

    Point p1(-4.0f, -2.0f);
    Point p2(4.0f, -2.0f);
    Point p3(4, 6);

    Point P(0.0f, 2.0f);
    Point PP(-2, 0);
    Point PPP(2, 2);
    std::cout << "Point P is inside the triangle: "
              << std::boolalpha << (bsp(p1, p2, p3, P)) << std::endl;
    std::cout << "Point PP is inside the triangle: "
              << std::boolalpha << (bsp(p1, p2, p3, PP)) << std::endl;
    std::cout << "Point PPP is inside the triangle: "
              << std::boolalpha << (bsp(p1, p2, p3, PPP)) << std::endl;
    return 0;
}
