#include "PmergeMe.hpp"

#include <iostream>
#include <stdexcept>
#include <ctime>

int main(int argc, char** argv) {
    try {
        PmergeMe pmerge(argc, argv);

        std::clock_t start, end;
        double elapsedVector, elapsedDeque;

        start = std::clock();
        pmerge.sortVector();
        end = std::clock();
        elapsedVector = (end - start);

        start = std::clock();
        pmerge.sortDeque();
        end = std::clock();
        elapsedDeque = (end - start);

        std::cout << "\nTime to process a range of " << pmerge.getVectorSize() << " elements with std::vector : " << elapsedVector << " microseconds." << std::endl;
        std::cout << "Time to process a range of " << pmerge.getDequeSize() << " elements with std::deque : " << elapsedDeque << " microseconds.\n" << std::endl;

        std::cout << "Number of comparisons: " << pmerge.getCounter() << "\n" << std::endl;

    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}