#include "PmergeMe.hpp"

#include <iostream>
#include <stdexcept>
#include <chrono>

int main(int argc, char** argv) {
    try {
        PmergeMe pmerge(argc, argv);

        std::chrono::system_clock::time_point start;
        std::chrono::system_clock::time_point end;
        std::chrono::duration<double> elapsedVector;
        std::chrono::duration<double> elapsedDeque;

        start = std::chrono::system_clock::now();
        pmerge.sortVector();
        end = std::chrono::system_clock::now();
        elapsedVector = end - start;
        
        start = std::chrono::system_clock::now();
        pmerge.sortDeque();
        end = std::chrono::system_clock::now();
        elapsedDeque = end - start;

        std::cout << "\nsortVector took " << elapsedVector.count() * 1000000 << " microseconds." << std::endl;
        std::cout << "sortDeque took " << elapsedDeque.count() * 1000000 << " microseconds." << std::endl;

    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}