#include "RPN.hpp"

#include <iostream>
#include <cctype>


int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Error: Wrong number of arguments." << std::endl, 1);

    RPN rpn;
    
    try
    {
        std::cout << rpn.calculate(argv[1]) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}