#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <list>

class RPN {
private:
    std::stack<double, std::list<double> > stack;
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

public:
    RPN();
    ~RPN();

    double calculate(const std::string &expression);
};

#endif // RPN_HPP