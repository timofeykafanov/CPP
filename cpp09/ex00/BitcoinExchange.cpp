#include "BitcoinExchange.hpp"

#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange() {
    // Load default database file on initialization
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

// Helper method to validate date format YYYY-MM-DD
bool BitcoinExchange::isValidDateFormat(const std::string& date) {
    // Check if the format matches YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    // Check if all other characters are digits
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            continue;  // Skip the dash characters
        }
        if (!isdigit(date[i])) {
            return false;
        }
    }
    
    // Extract year, month, and day
    int year, month, day;
    std::istringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    
    // Validate ranges
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }
    
    // Check days in month (simplified version)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year and adjust February days
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
        // Skip header line
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        // Parse CSV line
        std::stringstream ss(line);
        std::string date, valueStr;
        
        if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) {
            // Trim whitespace
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
            
            // Parse value
            double value;
            std::istringstream iss(valueStr);
            
            if (!(iss >> value)) {
                std::cerr << "Warning: invalid value in database: " << line << std::endl;
                continue;
            }
            
            // Store exchange rate
            this->exchangeRates[date] = value;
        }
    }
    
    file.close();
    
    if (exchangeRates.empty()) {
        throw std::runtime_error("No valid exchange rates loaded from database");
    }
    
    // Debug: Print first and last dates in the database
    if (!exchangeRates.empty()) {
        std::map<std::string, double>::const_iterator first = exchangeRates.begin();
        std::map<std::string, double>::const_iterator last = exchangeRates.end();
        --last;
        
        std::cout << "Database loaded with " << exchangeRates.size() << " entries." << std::endl;
        std::cout << "Exchange rate data available from " << first->first << " to " << last->first << std::endl;
    }
}

void BitcoinExchange::parseFile(const std::string &input) {
    // Check if exchange rates are loaded
    if (exchangeRates.empty()) {
        throw std::runtime_error("No exchange rates loaded. Please load database first.");
    }

    std::ifstream file(input.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + input);
    }
    
    std::string line;
    bool isFirstLine = true;
    bool processedAny = false;
    
    while (std::getline(file, line)) {
        // Skip header line if it exists
        if (isFirstLine) {
            isFirstLine = false;
            // Check if this line looks like a header (contains "date" or similar)
            if (line.find("date") != std::string::npos || line.find("Date") != std::string::npos) {
                continue;
            }
        }
        
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        // Parse line
        std::stringstream ss(line);
        std::string date, valueStr;
        
        // Check if line contains the pipe character
        if (line.find('|') == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            // Trim whitespace
            date.erase(0, date.find_first_not_of(" \t"));
            date.erase(date.find_last_not_of(" \t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \t"));
            valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
            
            // Validate date format (YYYY-MM-DD)
            if (!isValidDateFormat(date)) {
                std::cout << "Error: invalid date format => " << date << std::endl;
                continue;
            }
            
            // Parse and validate value
            double value;
            std::istringstream iss(valueStr);
            
            if (!(iss >> value)) {
                std::cout << "Error: not a number => " << valueStr << std::endl;
                continue;
            }
            
            // Check value range
            if (value < 0) {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            
            if (value > 1000.0) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            
            // All validations passed, calculate exchange rate for this entry
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
    // Check if exchange rates database is loaded
    if (exchangeRates.empty()) {
        std::cout << "Error: No exchange rate data available" << std::endl;
        return;
    }
    
    // Get first and last available date from database for range checking
    std::map<std::string, double>::const_iterator firstDate = exchangeRates.begin();
    std::map<std::string, double>::const_iterator lastDate = exchangeRates.end();
    if (!exchangeRates.empty()) {
        --lastDate;  // Move to last element
    }
    
    // Handle dates that are too early
    if (date < firstDate->first) {
        std::cout << "Error: no exchange rate data available for date " << date << std::endl;
        return;
    }
    
    // Look for exact date match
    std::map<std::string, double>::const_iterator it = exchangeRates.find(date);

    // If exact date not found, find closest earlier date
    if (it == exchangeRates.end()) {
        // Find the first element that is not less than (>=) the given date
        it = exchangeRates.lower_bound(date);
        
        // If we're at the end, there's no date >= our date (future date), so use the latest available rate
        if (it == exchangeRates.end()) {
            std::cout << date << " => " << amount << " = " << amount * lastDate->second;
            std::cout << " (using latest available rate from " << lastDate->first << ")" << std::endl;
            return;
        }
        // If the iterator points to a date later than requested, go back one to get closest previous date
        else if (it->first > date && it != exchangeRates.begin()) {
            --it;
        }
    }

    // Calculate and display the result
    double exchangeRate = it->second;
    double result = amount * exchangeRate;
    
    // Set output format
    std::cout.precision(2);
    std::cout << std::fixed;
    
    std::cout << date << " => " << amount << " = " << result << std::endl;
}