#include <iostream>
#include "whatever.hpp"

class CustomType
{
public:
    CustomType(int value) : value(value) {}
    int getValue() const;

private:
    int value;
};

int CustomType::getValue() const
{
    return value;
}

std::ostream &operator<<(std::ostream &outputStream, CustomType const &src)
{
    outputStream << src.getValue();
    return outputStream;
}

void testCustomType()
{
    CustomType c1(5);
    CustomType c2(10);

    ::swap(c1, c2);
    std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
    // This line would result in a compilation error
    // because CustomType lacks comparison operators
    // std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
}

int main()
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    // uncomment this and compile will return error 'cause the two arguments have different types:
    /* int e = 2.3;
    float f = 3.2;

    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl; */

    testCustomType();

    return 0;
}