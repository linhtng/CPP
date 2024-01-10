#include "BitcoinExchange.hpp"

int fileUnvailable(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << RED "Error: cannot open file '" << filename << "'" RESET << std::endl;
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: btc <input_file>" << std::endl;
        return 1;
    }
    std::string inputFile = argv[1];
    std::string database = "data.csv";
    if (fileUnvailable(inputFile) || fileUnvailable(database))
        return 1;
    BitcoinExchange btcExchange(database);
    btcExchange.displayBitcoinValue(inputFile);
    return 0;
}