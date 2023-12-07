#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
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
        PSEUDO,
        UNKNOWN
    };
    template <typename T>
    static bool isConvertible(const std::string &literal);
    static int getLiteralType(const std::string &literal);
    static void convertToChar(const std::string &literal, int type);
    static void convertToInt(const std::string &literal, int type);
    static void convertToFloat(const std::string &literal, int type);
    static void convertToDouble(const std::string &literal, int type);

    static bool isFloatFormat(const std::string &literal);
    static bool endsWith(const std::string &literal, char c);
    static int countCharacter(const std::string &literal, char c);

public:
    static void convert(const std::string &literal);
};

#endif