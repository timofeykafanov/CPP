#include "PmergeMe.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) {
    try {
        PmergeMe pmerge(argc, argv);
        // Further processing can be done here
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}