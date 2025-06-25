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

    void sortVector();
    void sortDeque();
    
    template <typename Out>
    Out generateSequence(size_t length);

    template <typename T, typename U>
    T recursionPairing(T& container, T& biggerContainer, U &indices);

    template <typename T, typename U>
    void mergeInsert(T& container, T& biggerContainer, U &indices);
};

template <typename T, typename U>
T PmergeMe::recursionPairing(T& container, T& biggerContainer, U &indices) {
    if (container.size() == 1)
        return container;

    T bigger;
    U biggerIndices;
    static int level = 1;
    size_t i = 0;
    int n = 0;

    while (i < container.size() - 1) {
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

    if (container.size() % 2 == 1)
        container[i][level] = -1;

    ++level;
    recursionPairing(bigger, biggerContainer, indices);
    --level;

    T smaller;
    
    i = 0;
    while (i < bigger.size()) {
        smaller.push_back(bigger[i]);
        i += 2;
    }
    
    U smallerIndices = generateSequence<U>(smaller.size());
    
    T reorderedSmaller;
    std::vector<bool> used(smaller.size(), false);

    for (size_t b = 0; b < biggerContainer.size(); ++b) {
        int second = biggerContainer[b][1];
        for (size_t s = 0; s < smaller.size(); ++s) {
            if (!used[s] && smaller[s][1] == second) {
                reorderedSmaller.push_back(smaller[s]);
                used[s] = true;
                break;
            }
        }
    }

    for (size_t s = 0; s < smaller.size(); ++s) {
        if (!used[s]) {
            reorderedSmaller.push_back(smaller[s]);
        }
    }

    smaller = reorderedSmaller;
    
    if (bigger.size() == 1) {
        biggerContainer.push_back(bigger[0]);
    } else {
        i = 0;
        while (i < smaller.size()) {
            size_t j = 0;
            while (j < biggerContainer.size()) {
                if (smaller[smallerIndices[i]].back() == -1 || smaller[smallerIndices[i]].back() == biggerContainer[j].back()) {
                    size_t left = 0;
                    size_t right = j;
                    if (smaller[smallerIndices[i]].back() == -1)
                        right = biggerContainer.size();
                    while (left < right) {
                        size_t mid = left + (right - left) / 2;
                        ++counter;
                        if (biggerContainer[mid][0] < smaller[smallerIndices[i]][0]) {
                            left = mid + 1;
                        } else {
                            right = mid;
                        }
                    }

                    biggerContainer.insert(biggerContainer.begin() + left, smaller[smallerIndices[i]]);
                    break;
                }
                ++j;
            }
            ++i;
        }
        
    }

    size_t k = 0;
    while (k <= biggerContainer.size() - 1 && biggerContainer[k].size() > 1) {
        biggerContainer[k].pop_back();
        ++k;
    }

    return biggerContainer;
}

template <typename T, typename U>
void PmergeMe::mergeInsert(T& container, T& biggerContainer, U &indices) {
    counter = 0;
    T biggerSorted;
    T smaller;
    biggerSorted = recursionPairing(container, biggerContainer, indices);

    size_t i = 0;
    while (i < container.size()) {
        smaller.push_back(container[i]);
        i += 2;
    }

    U smallerIndices = generateSequence<U>(smaller.size());

    T reorderedSmaller;
    U used(smaller.size(), 0);

    for (size_t b = 0; b < biggerSorted.size(); ++b) {
        int second = biggerSorted[b][1];
        for (size_t s = 0; s < smaller.size(); ++s) {
            if (!used[s] && smaller[s][1] == second) {
                reorderedSmaller.push_back(smaller[s]);
                used[s] = 1;
                break;
            }
        }
    }

    for (size_t s = 0; s < smaller.size(); ++s) {
        if (!used[s]) {
            reorderedSmaller.push_back(smaller[s]);
        }
    }

    smaller = reorderedSmaller;

    i = 0;
    while (i < smaller.size()) {
        size_t j = 0;
        while (j < biggerSorted.size()) {
            if (biggerSorted[j][1] == smaller[smallerIndices[i]][1]
                || smallerIndices[i] == - 1) {
                size_t left = 0;
                size_t right = j;
                if (smallerIndices[i] == - 1)
                    right = biggerSorted.size();
                if (smallerIndices[i] == (int)smaller.size() - 1)
                    right = biggerSorted.size();
                while (left < right) {
                    size_t mid = left + (right - left) / 2;
                    ++counter;
                    if (biggerSorted[mid][0] < smaller[smallerIndices[i]][0]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }

                biggerSorted.insert(biggerSorted.begin() + left, smaller[smallerIndices[i]]);
                break;
            }
            ++j;
        }
        ++i;
    }

    std::cout << "\nFinal sequence: ";
    for (typename T::iterator it = biggerSorted.begin(); it != biggerSorted.end(); ++it) {
        std::cout << (*it)[0] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nInitial length: " << container.size() << std::endl;
    std::cout << "\nFinal length: " << biggerSorted.size() << std::endl;

    std::cout << "\nNumber of comparisons: " << counter << std::endl;
}

template <typename Out>
Out PmergeMe::generateSequence(size_t length) {
    if (length == 0)
        throw std::invalid_argument("Length must be greater than 0.");
    Out indices;
    if (length == 1) {
        indices.push_back(0);
        return indices;
    }
    int secLastJacob = 1;
    int lastJacob = 1;
    if (length > 0) {
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
            if (jacob >= (int)length)
                break;
        }

        for (size_t i = 0; i < indices.size(); ++i) {
            if (i >= length)
                indices.pop_back(), i--;
            else
                indices[i]--;
        }
    }

    for (size_t i = 0; i < indices.size(); ++i) {
        if (indices[i] >= (int)length) {
            indices[i] = (int)length - 1;
            --length;
        }
    }

    return indices;
}

#endif // PmergeMe.hpp