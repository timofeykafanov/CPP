#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange;

    try {
        bitcoinExchange.parseFile(argv[1]);
        // bitcoinExchange.calculateExchangeRate("2023-10-01", 100.0);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
