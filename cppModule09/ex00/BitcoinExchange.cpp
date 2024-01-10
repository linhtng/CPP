#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& database) {
    this->readBitcoinPrices(database);
    /* if (prices.empty()) {
        std::cout << "The prices map is empty." << std::endl;
    } else {
        for(std::map<std::string, double>::const_iterator it = prices.begin(); it != prices.end(); ++it)
            std::cout << it->first << ", " << std::setprecision(10) << it->second << "\n";
    } */
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src): prices(src.prices) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    prices = src.prices;
    return *this;
}

void BitcoinExchange::readBitcoinPrices(const std::string& database) {
    std::ifstream file(database);
    std::string line;
    std::getline(file, line);
    std::regex pattern("(\\d{4}-\\d{2}-\\d{2}),(\\d+(?:\\.\\d+)?)");

    while (std::getline(file, line)) {
        std::smatch matches;
        if (std::regex_search(line, matches, pattern)) {
            std::string date = matches[1].str();
            double price = std::stod(matches[2].str());
            prices[date] = price;
        }
    }
} 

bool BitcoinExchange::isValidDate(const std::string& date) {
    std::istringstream iss(date);
    int year, month, day;
    char delimiter;
    if (iss >> year >> delimiter >> month >> delimiter >> day) {
        if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            return true;
        }
    }
    std::cout << "Error: invalid date.\n";
    return false;
}

bool BitcoinExchange::isValidValue(double value) {
    if (value < 0)
        std::cout << RED "Error: not a positive number.\n" RESET;
    if (value > 1000)
        std::cout << RED "Error: too large a number.\n" RESET;
    return value >= 0 && value <= 1000;
}

double BitcoinExchange::findClosestPrice(const std::string& date) {
    std::map<std::string, double>::iterator lower = prices.lower_bound(date);
    if (lower == prices.begin()) {
        return lower->second;
    } else if (lower == prices.end()) {
        return std::prev(lower)->second;
    } else {
        std::map<std::string, double>::iterator prev = std::prev(lower);
        if (lower->first.compare(date) < date.compare(prev->first)) {
            return lower->second;
        } else {
            return prev->second;
        }
    }
}

void BitcoinExchange::calculateExchangeRate(const std::string& inputFile) {
    std::ifstream file(inputFile);
    std::string line;
    std::regex lineRegex("(\\d{4}-\\d{2}-\\d{2})\\s\\|\\s(-?[\\d.]+)");
     while (std::getline(file, line)) {
        std::smatch match;
        if (std::regex_match(line, match, lineRegex)) {
            std::string date = match[1];
            double value = std::stod(match[2]);

            // Process the valid line
            // You can store the date and value in your desired data structure or perform any other operations here
            if (isValidDate(date) && isValidValue(value))
                std::cout << "Valid line: " << line << std::endl;
        } else if (line != "date | value"){
            std::cout << RED "Error: bad input => " << line << RESET << std::endl;
        }
    }
    /* while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double value;
        char delimiter;

        if (iss >> date >> delimiter >> value && delimiter == '|') {
            if (isValidDate(date) && isValidValue(value)) {
                std::cout << "Valid input: " << line << std::endl;
                // double price = findClosestPrice(date);
                // double exchangeRate = value * price;
                // std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << exchangeRate << std::endl;
            }
        } else if (line != "date | value"){
            std::cout << RED "Error: bad input => " << line << RESET << std::endl;
        }
    } */
}