#include "PmergeMe.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) {
    try {
        PmergeMe pmerge(argc, argv);
        pmerge.sortVector();
        // pmerge.sortDeque();
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}