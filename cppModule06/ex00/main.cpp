#include "ScalarConverter.hpp"

int main(int arc, char **arv)
{
    if (arc != 2)
    {
        std::cout << "Give as parameter a string representation of a C++ literal"
                  << "which belong to one of the following a scalar types: "
                  << "char, int, float, double" << std::endl;
        return 0;
    }
    ScalarConverter::convert(arv[1]);
    return 0;
}