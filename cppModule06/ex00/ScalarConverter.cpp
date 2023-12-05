#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return *this;
}

int ScalarConverter::convert(const std::string &literal)
{
}

int ScalarConverter::countCharacter(const std::string &literal, char c)
{
    int count = 0;
    std::string s(literal);
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        if (*it == c)
            count++;
    }
    return count;
}

bool ScalarConverter::endsWith(const std::string &literal, char c)
{
    return (literal[literal.length() - 1] == c);
}

bool ScalarConverter::isFloatFormat(const std::string &literal)
{
    if (countCharacter(literal, '.') == 1 &&
        (countCharacter(literal, 'f') == 1 || countCharacter(literal, 'F') == 1) &&
        (endsWith(literal, 'f') || endsWith(literal, 'F')))
        return true;
    return false;
}

int ScalarConverter::getLiteralType(const std::string &literal)
{
    if (literal.length() == 1 && isalpha(literal[0]))
        return CHAR;
    if (isFloatFormat(literal))
        return FLOAT;
    if (countCharacter(literal, '.') == 1)
        return DOUBLE;
    else if (isdigit(literal[0]))
    {
        for (int i = 1; i < literal.length(); ++i)
        {
            if (!isdigit(literal[i]))
            {
                return UNKNOWN;
            }
        }
        return INT;
    }
    else
    {
        return UNKNOWN;
    }
}

void ScalarConverter::handleChar(const std::string &literal)
{
}

void ScalarConverter::handleInt(const std::string &literal)
{
}

void ScalarConverter::handleFloat(const std::string &literal)
{
}

void ScalarConverter::handleDouble(const std::string &literal)
{
}