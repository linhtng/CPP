#include "BitcoinExchange.hpp"

int isFileAccessible(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error: cannot open file '" << filename << "'" << std::endl;
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: btc <input_file>" << std::endl;
        return 1;
    }
    std::string inputFile = argv[1];
    std::string database = "data2.csv";
    if (isFileAccessible(inputFile) || isFileAccessible(database))
        return 1;
    BitcoinExchange btcExchange(database);
    btcExchange.calculateExchangeRate(inputFile);
    return 0;
}