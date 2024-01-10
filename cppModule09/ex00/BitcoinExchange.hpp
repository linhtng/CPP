#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip> // for std::get_time
#include <regex>
#include <chrono>

#define RED "\e[91m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const std::string &database);
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);
    ~BitcoinExchange();

    void displayBitcoinValue(const std::string &inputFile);

private:
    std::map<std::string, double> prices;

    void readBitcoinPrices(const std::string &database);
    bool isValidDate(const std::string &date);
    bool isValidValue(double value);
    double findClosestPrice(const std::string &date);
};

#endif