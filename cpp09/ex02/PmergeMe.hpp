#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
private:
    std::vector<int> indicesVector;
    std::deque<int> indicesDeque;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

public:
    std::vector<std::vector<int> > vector;
    std::deque<std::deque<int> > deque;
    PmergeMe(int argc, char** argv);
    ~PmergeMe();
    
    template <typename Out, typename In>
    Out generateSequence(In &container);
    template <typename T>
    void mergeInsert(T& container);
};

template <typename T>
void PmergeMe::mergeInsert(T& container) {
    (void)container; // Suppress unused parameter warning
    
}

template <typename Out, typename In>
Out PmergeMe::generateSequence(In &container) {
    Out indices;
    int n = container.size() / 2 + container.size() % 2;
    int secLastJacob = 1;
    int lastJacob = 1;
    if (n > 0) {
        int jacob = 1;
        int j1 = jacob, j2 = 0, filler = 0;
        while (true) {
            jacob = j1 + 2 * j2;
            indices.push_back(jacob);
            j2 = j1;
            j1 = jacob;
            secLastJacob = j2 - 1;
            lastJacob = j1 - 1;
            filler = jacob - 1;
            while (filler > j2){
                indices.push_back(filler);
                --filler;
            }
            if (jacob >= n)
                break;
        }

        for (size_t i = 0; i < indices.size(); ++i) {
            if ((int)i >= n)
                indices.pop_back(), i--;
            else
                indices[i]--;
        }
    }

    int count = 0;
    size_t i = indices.size() - 1;
    int last = indices[i];
    int curr = indices[i - 1];
    int next = last;

    if (lastJacob == last) {
        indices[i] = secLastJacob + 1;
    } else if (last != secLastJacob + 1) {
        while (i > 0) {
            if (curr - 1 == next) {
                curr = indices[i - 1];
                next = indices[i];
                ++count;
                --i;
            } else {
                ++i;
                break;
            }
        }
        
        while (i < indices.size()) {
            indices[i] = indices[i] - secLastJacob + count;
            ++i;
        }
    }

    std::cout << "Jacobsthal indices: ";
    for (size_t i = 0; i < indices.size(); ++i) {
        std::cout << indices[i];
        if (i != indices.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return indices;
}

#endif // PmergeMe.hpp