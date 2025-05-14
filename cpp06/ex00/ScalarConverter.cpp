#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool isChar(const std::string& literal) {
    return (literal.length() == 1 && !isdigit(literal[0]));
}

bool isInt(const std::string& literal) {
    if (literal.empty())
        return false;
    
    int num;
    std::stringstream ss(literal);
    ss >> num;

    if (ss.fail())
        return false;

    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i]))
            return false;
    }
    
    return true;
}

bool isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "inff" || literal == "+inff" || literal == "-inff")
        return true;
    
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    
    std::string temp = literal.substr(0, literal.length() - 1);
    
    float num;
    std::stringstream ss(literal);
    ss >> num;

    if (ss.fail())
        return false;

    bool hasDecimalPoint = false;
    size_t i = 0;
    
    if (temp[0] == '-' || temp[0] == '+')
        i++;
    
    for (; i < temp.length(); i++) {
        if (temp[i] == '.') {
            if (hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        } else if (!isdigit(temp[i])) {
            return false;
        }
    }
    
    return hasDecimalPoint;
}

bool isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "inf" || literal == "+inf" || literal == "-inf") 
        return true;

    double num;
    std::stringstream ss(literal);
    ss >> num;

    if (ss.fail())
        return false;
    
    bool hasDecimalPoint = false;
    size_t i = 0;
    
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimalPoint)
                return false;
            hasDecimalPoint = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    
    return hasDecimalPoint;
}

void printChar(char c) {
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void printFloat(float f) {
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void printDouble(double d) {
    std::cout << "double: " << d << std::endl;
}

void convertFromChar(char c) {
    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void convertFromInt(int i) {
    if (i >= 0 && i <= 127)
        printChar(static_cast<char>(i));
    else
        std::cout << "char: impossible" << std::endl;
    
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void convertFromFloat(float f) {
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<char>(f));
    if (std::isnan(f) || std::isinf(f) || f > static_cast<float>(std::numeric_limits<int>::max()) || f < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        printInt(static_cast<int>(f));
    
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void convertFromDouble(double d) {
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else
        printChar(static_cast<char>(d));
    
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        printInt(static_cast<int>(d));
    
    if (std::isnan(d) || std::isinf(d))
        printFloat(static_cast<float>(d));
    else if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        printFloat(static_cast<float>(d));
    
    printDouble(d);
}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        char c = literal[0];
        convertFromChar(c);
    }
    else if (isInt(literal)) {
        int i;
        std::stringstream iss(literal);
        iss >> i;
        convertFromInt(i);
    }
    else if (isFloat(literal)) {
        float f;
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else {
            std::string temp = literal.substr(0, literal.length() - 1);
            f = std::strtof(temp.c_str(), NULL);
        }
        convertFromFloat(f);
    }
    else if (isDouble(literal)) {
        double d;
        if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else
            d = std::strtod(literal.c_str(), NULL);
        convertFromDouble(d);
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
