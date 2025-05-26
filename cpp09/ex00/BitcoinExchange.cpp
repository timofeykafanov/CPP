#include "BitcoinExchange.hpp"

#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange() {
    try {
        readDatabaseFile("data.csv");
    } catch (const std::exception &e) {
        std::cerr << "Warning: " << e.what() << std::endl;
        std::cerr << "Exchange rates not loaded. Please provide a valid database file." << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : exchangeRates(src.exchangeRates) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src) {
        this->exchangeRates = src.exchangeRates;
    }
    return *this;
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (!isdigit(date[i])) {
            return false;
        }
    }
    
    int year, month, day;
    std::istringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }
    
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[2] = 29;
    }
    
    if (day > daysInMonth[month]) {
        return false;
    }
    
    return true;
}

void BitcoinExchange::readDatabaseFile(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open database file: " + filename);
    }
    
    std::string line;
    bool isFirstLine = true;
    
    while (std::getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        
        if (line.empty()) {
            continue;
        }
        
        std::stringstream ssLine(line);
        std::string date, valueStr;
        
        if (std::getline(ssLine, date, ',') && std::getline(ssLine, valueStr)) {
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
            
            double value;
            std::stringstream ssValue(valueStr);
            
            if (!(ssValue >> value)) {
                std::cerr << "Warning: invalid value in database: " << line << std::endl;
                continue;
            }
            
            this->exchangeRates[date] = value;
        }
    }
    
    file.close();
    
    if (exchangeRates.empty()) {
        throw std::runtime_error("No valid exchange rates loaded from database");
    }
    
    if (!exchangeRates.empty()) {
        std::map<std::string, double>::iterator first = exchangeRates.begin();
        std::map<std::string, double>::iterator last = exchangeRates.end();
        --last;
        
        std::cout << "Database loaded with " << exchangeRates.size() << " entries." << std::endl;
        std::cout << "Exchange rate data available from " << first->first << " to " << last->first << std::endl;
    }
}

void BitcoinExchange::parseFile(const std::string &input) {
    if (exchangeRates.empty()) {
        throw std::runtime_error("No exchange rates loaded.");
    }

    std::ifstream file(input.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + input);
    }
    
    std::string line;
    bool isFirstLine = true;
    bool processedAny = false;
    
    while (std::getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            if (line.find("date") != std::string::npos || line.find("value") != std::string::npos) {
                continue;
            }
        }
        
        if (line.empty()) {
            continue;
        }
        
        std::stringstream ss(line);
        std::string date, valueStr;
        
        if (line.find('|') == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
            
            if (!isValidDateFormat(date)) {
                std::cout << "Error: invalid date format => " << date << std::endl;
                continue;
            }
            
            double value;
            std::stringstream iss(valueStr);

            if (iss.fail()) {
                std::cout << "Error: overflow => " << valueStr << std::endl;
                continue;
            }
            
            if (!(iss >> value) || !iss.eof()) {
                std::cout << "Error: not a number => " << valueStr << std::endl;
                continue;
            }
            
            if (value < 0) {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            
            if (value > 1000.0) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            
            calculateExchangeRate(date, value);
            processedAny = true;
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
    
    file.close();
    
    if (!processedAny) {
        std::cout << "Warning: No valid input data was processed." << std::endl;
    }
}

void BitcoinExchange::calculateExchangeRate(const std::string &date, double amount) {
    if (exchangeRates.empty()) {
        std::cout << "Error: No exchange rate data available" << std::endl;
        return;
    }
    
    std::map<std::string, double>::iterator firstDate = exchangeRates.begin();
    std::map<std::string, double>::iterator lastDate = exchangeRates.end();
    --lastDate;
    
    if (date < firstDate->first) {
        std::cout << "Error: no exchange rate data available for date " << date << std::endl;
        return;
    }
    
    std::map<std::string, double>::iterator it = exchangeRates.find(date);

    if (it == exchangeRates.end()) {
        it = exchangeRates.lower_bound(date);
        
        if (it == exchangeRates.end()) {
            std::cout << date << " => " << amount << " = " << amount * lastDate->second;
            std::cout << " (using latest available rate from " << lastDate->first << ")" << std::endl;
            return;
        }
        else if (it->first > date && it != exchangeRates.begin()) {
            --it;
        }
    }

    double exchangeRate = it->second;
    double result = amount * exchangeRate;
    
    std::cout.precision(2);
    std::cout << std::fixed;
    
    std::cout << date << " => " << amount << " = " << result << std::endl;
}