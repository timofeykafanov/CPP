#include "BitcoinExchange.hpp"

// #include <sstream>
// #include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : exchangeRates(src.exchangeRates), inputData(src.inputData) {
    (void)src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src) {
        this->exchangeRates = src.exchangeRates;
        this->inputData = src.inputData;
    }
    return *this;
}
void BitcoinExchange::parseFile(const std::string &input) {
    
    (void)input;
}

void BitcoinExchange::calculateExchangeRate(const std::string &date, double amount) {

    // float exchangeRate = 0.0f;
    (void)date;
    (void)amount;

}