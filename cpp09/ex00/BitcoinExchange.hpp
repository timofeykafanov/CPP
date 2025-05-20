#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {

private:
    std::map<std::string, std::string> exchangeRates;
    std::map<std::string, std::string> inputData;

    // void parseDate(const std::string &date);
    // void validateAmount(float amount);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &rhs);

    void parseFile(const std::string &input);
    void calculateExchangeRate(const std::string &date, double amount);
};



#endif // BITCOINEXCHANGE_HPP