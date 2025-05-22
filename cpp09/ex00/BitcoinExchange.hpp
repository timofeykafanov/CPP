#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {

private:
    std::map<std::string, double> exchangeRates;

    bool isValidDateFormat(const std::string &date);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &rhs);

    void readDatabaseFile(const std::string &filename);
    void parseFile(const std::string &input);
    void calculateExchangeRate(const std::string &date, double amount);
};



#endif // BITCOINEXCHANGE_HPP