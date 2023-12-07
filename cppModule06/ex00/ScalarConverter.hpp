#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <ctype.h>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &src);
    ~ScalarConverter();

    enum LiteralType
    {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        UNKNOWN
    };

    double doubleLiteral;
    int intLiteral;

    static int getLiteralType(const std::string &literal);
    static void handleChar(const std::string &literal);
    static void handleInt(const std::string &literal);
    static void handleFloat(const std::string &literal);
    static void handleDouble(const std::string &literal);
    static bool isFloatFormat(const std::string &literal);
    static bool endsWith(const std::string &literal, char c);
    static int countCharacter(const std::string &literal, char c);

public:
    static int convert(const std::string &literal);
};

#endif