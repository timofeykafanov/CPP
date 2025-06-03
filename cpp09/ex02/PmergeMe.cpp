#include "PmergeMe.hpp"

#include <stdexcept>
#include <iostream>
#include <sstream>

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv) {
    if (argc != 2)
        throw std::invalid_argument("Wrong amout of arguments. Usage: ./PmergeMe \"<list of integers>\"");
    
    std::vector<std::string> tokens;
    std::string arg1(argv[1]);
    size_t pos = 0, found;
    while ((found = arg1.find_first_of(' ', pos)) != std::string::npos) {
        if (found > pos)
            tokens.push_back(arg1.substr(pos, found - pos));
        pos = found + 1;
    }
    if (pos < arg1.size())
        tokens.push_back(arg1.substr(pos));

    for (size_t i = 0; i < tokens.size(); ++i) {
        int value;
        std::stringstream ss(tokens[i]);
        if (!(ss >> value) || !ss.eof() || ss.fail())
            throw std::invalid_argument("Invalid integer value in input.");
        if (value < 0)
            throw std::invalid_argument("Negative values are not allowed.");
        if (tokens[i].find('+') != std::string::npos || tokens[i].find('-') != std::string::npos)
            throw std::invalid_argument("+ or - are not allowed in the input.");
        std::vector<int> tempVec;
        tempVec.push_back(value);
        vector.push_back(tempVec);

        std::deque<int> tempDeq;
        tempDeq.push_back(value);
        deque.push_back(tempDeq);
    }

    generateSequence();
}

void PmergeMe::generateSequence(void) {
    int n = vector.size() / 2 + vector.size() % 2;
    int secLastJacob = 1;
    int lastJacob = 1;
    if (n > 0) {
        int jacob = 1;
        int j1 = jacob, j2 = 0, filler = 0;
        while (true) {
            jacob = j1 + 2 * j2;
            indexes.push_back(jacob);
            j2 = j1;
            j1 = jacob;
            secLastJacob = j2 - 1;
            lastJacob = j1 - 1;
            filler = jacob - 1;
            while (filler > j2){
                indexes.push_back(filler);
                --filler;
            }
            if (jacob >= n)
                break;
        }

        for (size_t i = 0; i < indexes.size(); ++i) {
            if ((int)i >= n)
                indexes.pop_back(), i--;
            else
                indexes[i]--;
        }
    }

    int count = 0;
    size_t i = indexes.size() - 1;
    int last = indexes[i];
    int curr = indexes[i - 1];
    int next = last;

    if (lastJacob == last) {
        indexes[i] = secLastJacob + 1;
    } else if (last != secLastJacob + 1) {
        while (i > 0) {
            if (curr - 1 == next) {
                curr = indexes[i - 1];
                next = indexes[i];
                ++count;
                --i;
            } else {
                ++i;
                break;
            }
        }
        
        while (i < indexes.size()) {
            indexes[i] = indexes[i] - secLastJacob + count;
            ++i;
        }
    }

    std::cout << "Jacobsthal indexes: ";
    for (size_t i = 0; i < indexes.size(); ++i) {
        std::cout << indexes[i];
        if (i != indexes.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}
