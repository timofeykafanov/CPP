#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
private:
    std::vector<std::vector<int> > vector;
    std::deque<std::deque<int> > deque;
    std::vector<int> indicesVector;
    std::deque<int> indicesDeque;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe();

    void sortVector() { mergeInsert(vector); }
    void sortDeque() { mergeInsert(deque); }
    
    template <typename Out, typename In>
    Out generateSequence(In &container);

    template <typename T>
    void recursionPairing(T& container);

    template <typename T>
    void mergeInsert(T& container);
};

template <typename T>
void PmergeMe::recursionPairing(T& container) {
    if (container.size() == 1)
        return;

    T bigger;
    size_t i = 0;
    int n = 0;
    while (i < container.size() - 1) {
        if (i == container.size() - 1) break;
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
        container[i].push_back(n);
        container[i + 1].push_back(n);
        bigger.push_back(container[i + 1]);
        i += 2;
        ++n;
    }
    std::cout << "bigger: ";
    for (typename T::iterator it = bigger.begin(); it != bigger.end(); ++it) {
        std::cout << "[";
        for (typename T::value_type::iterator jt = it->begin(); jt != it->end(); ++jt) {
            std::cout << *jt;
            if (jt + 1 != it->end())
            std::cout << " ";
        }
        std::cout << "]";
        if (it + 1 != bigger.end())
        std::cout << " ";
    }
    std::cout << std::endl;
    recursionPairing(bigger);
}

template <typename T>
void PmergeMe::mergeInsert(T& container) {
    // (void)container; // Suppress unused parameter warning
    recursionPairing(container);
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