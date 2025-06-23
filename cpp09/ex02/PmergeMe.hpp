#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
private:
    std::vector<std::vector<int> > vector;
    std::deque<std::deque<int> > deque;
    std::vector<std::vector<int> > biggerVector;
    std::deque<std::deque<int> > biggerDeque;
    std::vector<int> indicesVector;
    std::deque<int> indicesDeque;
    int counter;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe();

    void sortVector() { mergeInsert(vector, biggerVector); }
    void sortDeque() { mergeInsert(deque, biggerDeque); }
    
    template <typename Out, typename In>
    Out generateSequence(In &container);

    template <typename T>
    void recursionPairing(T& container, T& biggerContainer);

    template <typename T>
    void mergeInsert(T& container, T& biggerContainer);
};

template <typename T>
void PmergeMe::recursionPairing(T& container, T& biggerContainer) {
    if (container.size() == 1)
        return;

    T bigger;
    static int level = 1;
    std::cout << "\nRecursion level: " << level << "  ++++++++++++++++++++++++++++++++++++" << std::endl;
    size_t i = 0;
    int n = 0;

    while (i <= container.size() - 1) {
        ++counter;
        if (container[i] > container[i + 1]) {
            std::swap(container[i], container[i + 1]);
        }
        if (level == 1) {
            container[i].push_back(n);
            container[i + 1].push_back(n);
        }
        bigger.push_back(container[i + 1]);
        bigger[n].push_back(n / 2);
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
    
    ++level;
    recursionPairing(bigger, biggerContainer);
    --level;

    std::cout << "\nRecursion level: " << level << "  -----------------------------------------------------" << std::endl;

    if (bigger.size() == 1) {
        biggerContainer.push_back(bigger[0]);
    } else {
        i = 0;
        while (i <= bigger.size() - 1) {
            size_t j = 0;
            while (j < biggerContainer.size()) {
                if (bigger[i].back() == biggerContainer[j].back()) {
                    size_t left = 0;
                    size_t right = j;
                    while (left < right) {
                        size_t mid = left + (right - left) / 2;
                        ++counter;
                        if (biggerContainer[mid][0] < bigger[i][0]) {
                            left = mid + 1;
                        } else {
                            right = mid;
                        }
                    }

                    biggerContainer.insert(biggerContainer.begin() + left, bigger[i]);
                    break;
                }
                ++j;
            }
            
            i += 2;
        }
        
    }

    size_t k = 0;
    while (k <= biggerContainer.size() - 1 && biggerContainer[k].size() > 1) {
        biggerContainer[k].pop_back();
        ++k;
    }

    std::cout << "biggerContainer: ";
    for (typename T::iterator it = biggerContainer.begin(); it != biggerContainer.end(); ++it) {
        std::cout << "[";
        for (typename T::value_type::iterator jt = it->begin(); jt != it->end(); ++jt) {
            std::cout << *jt;
            if (jt + 1 != it->end())
            std::cout << " ";
        }
        std::cout << "]";
        if (it + 1 != biggerContainer.end())
        std::cout << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void PmergeMe::mergeInsert(T& container, T& biggerContainer) {
    // (void)container; // Suppress unused parameter warning
    counter = 0;
    recursionPairing(container, biggerContainer);
    std::cout << "Number of comparisons: " << counter << std::endl;
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