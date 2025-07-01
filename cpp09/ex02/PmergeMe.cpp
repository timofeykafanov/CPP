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

    if (vector.empty() || deque.empty())
        throw std::invalid_argument("Input cannot be empty.");
}

void PmergeMe::sortVector() {
    mergeInsert<std::vector<std::vector<int> >, std::vector<int> >(vector, biggerVector);
}

void PmergeMe::sortDeque() {
    mergeInsert<std::deque<std::deque<int> >, std::deque<int> >(deque, biggerDeque);
}

int PmergeMe::getCounter() const { return counter; }
int PmergeMe::getVectorSize() const { return vector.size(); }
int PmergeMe::getDequeSize() const { return deque.size(); }
