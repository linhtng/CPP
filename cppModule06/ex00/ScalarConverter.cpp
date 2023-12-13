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
    // std::cout << "type: " << type << '\n';
    try
    {
        switch (type)
        {
        case CHAR:
            convertToChar(literal);
            break;
        case INT:
            convertToInt(literal);
            break;
        case FLOAT:
            convertToFloat(literal);
            break;
        case DOUBLE:
            convertToDouble(literal);
            break;
        case PSEUDOINF:
            convertToPseudoInf(literal);
            break;
        case PSEUDONAN:
            convertToPseudoNan();
            break;
        default:
            std::cout << "Error: Unknown type of literal" << std::endl;
        }
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
    std::string floatStr(literal.begin(), literal.end() - 1);

    if (literal.length() == 1 && isalpha(literal[0]))
        return CHAR;
    if (isFloatFormat(literal) && isConvertible<float>(floatStr))
        return FLOAT;
    if (countCharacter(literal, '.') == 1 && isConvertible<double>(literal) && !endsWith(literal, '.'))
        return DOUBLE;
    if (isConvertible<int>(literal))
        return INT;
    const std::string pseudoList[6] = {"-inff", "+inff",
                                       "-inf", "+inf", "nanf", "nan"};
    for (int i = 0; i < 6; ++i)
    {
        if (pseudoList[i] == literal)
        {
            if (i <= 3)
                return PSEUDOINF;
            else
                return PSEUDONAN;
        }
    }
    return UNKNOWN;
}

void ScalarConverter::convertToChar(const std::string &literal)
{
    printChar(static_cast<int>(literal[0]));
    int intValue = static_cast<int>(literal[0]);
    float floatValue = static_cast<float>(literal[0]);
    double doubleValue = static_cast<double>(literal[0]);

    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << floatValue << "f" << std::endl;
    std::cout << "double: " << doubleValue << std::endl;
}

void ScalarConverter::convertToInt(const std::string &literal)
{
    std::istringstream stream(literal);
    int value;
    if (!(stream >> value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        // Overflow
        std::cout << "impossible" << std::endl;
        return;
    }
    printChar(value);
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertToFloat(const std::string &literal)
{
    const std::string floatStr(literal.begin(), literal.end() - 1);
    std::istringstream stream(floatStr);
    float value;
    if (!(stream >> value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        // Overflow
        std::cout << "impossible" << std::endl;
        return;
    }
    printChar(value);
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    if (value == static_cast<int>(value))
    {
        std::cout << "float: " << value << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convertToDouble(const std::string &literal)
{
    std::istringstream stream(literal);
    double value;
    if (!(stream >> value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        // Overflow
        std::cout << "impossible" << std::endl;
        return;
    }
    printChar(value);
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    if (value == static_cast<int>(value))
    {
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double: " << value << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
}

template <typename T>
bool ScalarConverter::isConvertible(const std::string &literal)
{
    std::istringstream stream(literal);
    T value;

    stream >> value;

    // Check if the entire string was consumed and the conversion was successful
    return !stream.fail() && stream.eof();
}

void ScalarConverter::printChar(const int num)
{
    std::cout << "char: ";
    if (num > 32 && num < CHAR_MAX)
        std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
    else if (num <= 32 && num >= 0)
        std::cout << "Non displayble" << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::convertToPseudoInf(const std::string &literal)
{
    printChar(-1);
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << literal[0] << "inff\n";
    std::cout << "float: " << literal[0] << "inf\n";
}

void ScalarConverter::convertToPseudoNan()
{
    printChar(-1);
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}
