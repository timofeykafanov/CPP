#include "RPN.hpp"

#include <stdexcept>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) {
    *this = other;
}
RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->stack = other.stack;
    }
    return *this;
}

double RPN::calculate(const std::string &expression) {
    for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it) {
        if (std::isspace(*it)) {
            continue;
        } else if (std::isdigit(*it)) {
            stack.push(*it - '0');
        } else {
            if (stack.size() < 2) {
                throw std::runtime_error("Not enough operands.");
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            switch (*it) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Division by zero.");
                    stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Invalid operator.");
            }
        }
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Too many operands.");
    }
    return stack.top();
}
