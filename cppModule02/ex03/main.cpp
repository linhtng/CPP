#include "Point.hpp"

Fixed calculateTriangleArea(const Point &p1, const Point &p2, const Point &p3);
bool bsp(Point const A, Point const B, Point const C, Point const point);

int main()
{
    // Point p1(-1.0f, 2.0f);
    // Point p2(2.0f, 3.0f);
    // Point p3(4.0f, -3.0f);

    Point p1(-1.0f, 0.0f);
    Point p2(1.0f, 0.0f);
    Point p3(0, -1);

    Point P(0.0f, 0.5f);
    Point PP(-0.2f, -0.5f);
    Point PPP(0.0f, -0.5f);
    Point P4(0.0f, -1);
    Point P5(-0.5f, -0.5f);
    std::cout << "Point P is inside the triangle: "
              << std::boolalpha << (bsp(p1, p2, p3, P)) << std::endl;
    std::cout << "Point PP is inside the triangle: "
              << std::boolalpha << (bsp(p1, p2, p3, PP)) << std::endl;
    std::cout << "Point PPP is inside the triangle: "
              << std::boolalpha << (bsp(p1, p2, p3, PPP)) << std::endl;
    std::cout << "Point P4 is inside the triangle: "
              << std::boolalpha << (bsp(p1, p2, p3, P4)) << std::endl;
    std::cout << "Point P5 is inside the triangle: "
              << std::boolalpha << (bsp(p1, p2, p3, P5)) << std::endl;
    return 0;
}
