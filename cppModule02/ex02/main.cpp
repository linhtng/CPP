#include "Fixed.hpp"

void testCompare(Fixed const &a, Fixed const &b)
{
    std::cout << std::endl
              << "a: " << a << std::endl
              << "b: " << b << std::endl;
    std::cout << "a > b\t: " << std::boolalpha << (a > b) << std::endl;
    std::cout << "b > a\t: " << std::boolalpha << (b > a) << std::endl;
    std::cout << "a < b\t: " << std::boolalpha << (a < b) << std::endl;
    std::cout << "b < a\t: " << std::boolalpha << (b < a) << std::endl;
    std::cout << "a >= b\t: " << std::boolalpha << (a >= b) << std::endl;
    std::cout << "b >= a\t: " << std::boolalpha << (b >= a) << std::endl;
    std::cout << "a <= b\t: " << std::boolalpha << (a <= b) << std::endl;
    std::cout << "b <= a\t: " << std::boolalpha << (b <= a) << std::endl;
    std::cout << "a == b\t: " << std::boolalpha << (a == b) << std::endl;
    std::cout << "b == a\t: " << std::boolalpha << (b == a) << std::endl;
    std::cout << "a != b\t: " << std::boolalpha << (a != b) << std::endl;
    std::cout << "b != a\t: " << std::boolalpha << (b != a) << std::endl;
}

void testArithmeticOp(Fixed const &a, Fixed const &b)
{
    std::cout << std::endl
              << "a: " << a << std::endl
              << "b: " << b << std::endl;
    Fixed res = (a + b);
    std::cout << "a + b = " << a << " + " << b << " = " << res << std::endl;
    res = (a - b);
    std::cout << "a - b = " << a << " - " << b << " = " << res << std::endl;
    res = (a * b);
    std::cout << "a * b = " << a << " * " << b << " = " << res << std::endl;
    res = (a / b);
    std::cout << "a / b = " << a << " / " << b << " = " << res << std::endl;
}

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed const c(Fixed(3) / Fixed(12));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << c << std::endl;

    std::cout << Fixed::min(b, c) << std::endl;

    std::cout << "\nSome extra test\n";
    testArithmeticOp(Fixed(2), Fixed(4));
    testCompare(Fixed(42), Fixed(42));

    return 0;
}
