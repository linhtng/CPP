#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &database)
{
    this->readBitcoinPrices(database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : prices(src.prices) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    prices = src.prices;
    return *this;
}

void BitcoinExchange::readBitcoinPrices(const std::string &database)
{
    std::ifstream file(database);
    std::string line;
    std::getline(file, line);
    std::regex pattern("(\\d{4}-\\d{2}-\\d{2}),(\\d+(?:\\.\\d+)?)");

    while (std::getline(file, line))
    {
        std::smatch matches;
        if (std::regex_search(line, matches, pattern))
        {
            std::string date = matches[1].str();
            double price = std::stod(matches[2].str());
            prices[date] = price;
        }
    }
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

/* First, use std::get_time is used to parse the date from the input string to a tm object. Save the tm object to a copy, and then use std::mktime to normalize the tm object, meaning it adjusts the fields to represent a valid date. For example, February 29, 2023 is not a valid date because 2023 is not a leap year. However, std::mktime adjusts this to March 1, 2023, which is a valid date. Function mktime returns -1 if the date is invalid, then we compare the input date with the date produced by mktime. If they are the same, the input date is valid.
 */
bool BitcoinExchange::isValidDate(const std::string &date)
{
    std::istringstream iss(date);
    std::tm tm = {};
    if (iss >> std::get_time(&tm, "%Y-%m-%d"))
    {
        std::tm tm_copy = tm;
        if (std::mktime(&tm) != -1 && (tm.tm_year == tm_copy.tm_year &&
                                       tm.tm_mon == tm_copy.tm_mon &&
                                       tm.tm_mday == tm_copy.tm_mday))
            return true;
    }
    std::cout << RED "Error: invalid date => " << date << "\n" RESET;
    return false;
}

bool BitcoinExchange::isValidValue(double value)
{
    if (value < 0)
        std::cout << RED "Error: not a positive number.\n" RESET;
    if (value > 1000)
        std::cout << RED "Error: too large a number.\n" RESET;
    return value >= 0 && value <= 1000;
}

double BitcoinExchange::findClosestPrice(const std::string &date)
{
    std::map<std::string, double>::iterator lower = prices.lower_bound(date);
    if (lower == prices.begin())
    {
        std::cout << RED "Error: date too far in the past => " << date << "\n" RESET;
        return ERROR;
    }
    else
        return std::prev(lower)->second;
}

void BitcoinExchange::displayBitcoinValue(const std::string &inputFile)
{
    std::ifstream file(inputFile);
    std::string line;
    std::regex lineRegex("(\\d{4}-\\d{1,2}-\\d{1,2})\\s\\|\\s(-?[\\d.]+)");
    while (std::getline(file, line))
    {
        std::smatch match;
        if (std::regex_match(line, match, lineRegex))
        {
            std::string date = match[1];
            double value = std::stod(match[2]);
            if (isValidDate(date) && isValidValue(value))
            {
                double exchangeRate;
                std::map<std::string, double>::iterator it = prices.find(date);
                if (it != prices.end())
                    exchangeRate = it->second;
                else
                    exchangeRate = findClosestPrice(date);
                if (exchangeRate != ERROR)
                {
                    double result = value * exchangeRate;
                    std::cout << date << " => " << std::setprecision(10)
                              << value << " = " << result << std::endl;
                }
            }
        }
        else if (line != "date | value")
            std::cout << RED "Error: bad input => " << line << RESET << std::endl;
    }
}