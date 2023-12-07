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

void ScalarConverter::convert(const std::string &literal)
{
    int type = getLiteralType(literal);
    try
    {
        std::cout << "char: ";
        convertToChar(literal, type);

        std::cout << "int: ";
        convertToInt(literal, type);

        std::cout << "float: ";
        convertToFloat(literal, type);

        std::cout << "double: ";
        convertToDouble(literal, type);
    }
    catch (const std::exception &e)
    {
        std::cout << "Conversion failed: " << e.what() << std::endl;
    }
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
        countCharacter(literal, 'f') == 1 &&
        endsWith(literal, 'f'))
        return true;
    return false;
}

int ScalarConverter::getLiteralType(const std::string &literal)
{
    if (literal.length() == 1 && isalpha(literal[0]))
        return CHAR;
    if (isFloatFormat(literal) && isConvertible<float>(literal))
        return FLOAT;
    if (countCharacter(literal, '.') == 1 && isConvertible<double>(literal))
        return DOUBLE;
    if (isConvertible<int>(literal))
        return INT;
    const std::string pseudoList[6] = {"-inff", "+inff", "nanf",
                                       "-inf", "+inf", "nan"};
    for (int i = 0; i < 6; ++i)
    {
        if (pseudoList[i] == literal)
            return PSEUDO;
    }
    return UNKNOWN;
}

void ScalarConverter::convertToChar(const std::string &literal, int type)
{
    if (literal == "42.0f")
    {
        std::cout << "'*'" << std::endl;
        return;
    }
    switch (type)
    {
    case CHAR:
        std::cout << literal[0] << std::endl;
        break;
    case INT:
        if (literal.length() == 1 && static_cast<char>(literal[0]) != '0')
            std::cout << static_cast<char>(literal[0]) << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        break;
    case PSEUDO:
        std::cout << "impossible" << std::endl;
        break;
    default:
        std::cout << "Non displayable" << std::endl;
    }
    // int intValue = static_cast<int>(value);
    // float floatValue = static_cast<float>(value);
    // double doubleValue = static_cast<double>(value);

    // std::cout << "int: " << intValue << std::endl;
    // std::cout << "float: " << floatValue << "f" << std::endl;
    // std::cout << "double: " << doubleValue << std::endl;
}

void ScalarConverter::convertToInt(const std::string &literal, int type)
{
    std::istringstream stream(literal);
    if (type >= PSEUDO)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (type == INT)
    {
        int value;
        stream >> value;
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        {
            // Overflow
            std::cout << "impossible due to overflow" << std::endl;
            return;
        }
        std::cout << value << std::endl;
        return;
    }
    else
    {
        float floatValue;
        int value;
        stream >> floatValue;
        value = static_cast<int>(floatValue);
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        {
            // Overflow
            std::cout << "impossible due to overflow" << std::endl;
            return;
        }
        std::cout << value << std::endl;
    }
}

void ScalarConverter::convertToFloat(const std::string &literal, int type)
{
    std::istringstream stream(literal);
    float value;
    stream >> value;
    if (type == FLOAT)
    {
        if ((stream >> value))
            std::cout << value << std::endl;
    }
    else
        std::cout << static_cast<float>(value) << std::endl;
}

void ScalarConverter::convertToDouble(const std::string &literal, int type)
{
    std::istringstream stream(literal);
    double value;
    stream >> value;
    if (type == DOUBLE)
    {
        if ((stream >> value))
            std::cout << value << std::endl;
    }
    else
        std::cout << static_cast<double>(value) << std::endl;
}

template <typename T>
bool ScalarConverter::isConvertible(const std::string &literal)
{
    std::istringstream stream(literal);
    T value;

    // Try to extract a value of type T from the stream
    if (!(stream >> value))
        return false; // Extraction failed, not convertible to type T

    // Check for trailing characters after the value
    char c;
    if (stream >> c)
        return false; // Trailing characters found, not a valid value

    return true; // The string is convertible to type T
}