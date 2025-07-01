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
    int counter;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe();

    void sortVector();
    void sortDeque();

    int getCounter() const;
    int getVectorSize() const;
    int getDequeSize() const;
    
    template <typename Out>
    Out generateSequence(size_t length);

    template <typename T, typename U>
    T reorderSequence(T& smaller, T& bigger);

    template <typename T, typename U>
    void bynaryInsertionSort(T& biggerContainer, T& smaller, U &indices);

    template <typename T, typename U>
    T recursionPairing(T& container, T& biggerContainer);

    template <typename T, typename U>
    void mergeInsert(T& container, T& biggerContainer);
};

template <typename T, typename U>
T PmergeMe::reorderSequence(T& smaller, T& bigger) {
    T reorderedSmaller;
    U used(smaller.size(), 0);

    for (size_t b = 0; b < bigger.size(); ++b) {
        int second = bigger[b].back();
        for (size_t s = 0; s < smaller.size(); ++s) {
            if (!used[s] && smaller[s].back() == second) {
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

    return reorderedSmaller;
}

template <typename T, typename U>
void PmergeMe::bynaryInsertionSort(T& biggerContainer, T& smaller, U &indices) {
    size_t i = 0;
    while (i < indices.size()) {
        size_t j = 0;
        while (j < biggerContainer.size()) {
            if (smaller[indices[i]].back() == -1
                || smaller[indices[i]].back() == biggerContainer[j].back()) {
                size_t left = 0;
                size_t right = j;
                if (smaller[indices[i]].back() == -1)
                    right = biggerContainer.size();
                while (left < right) {
                    size_t mid = left + (right - left) / 2;
                    ++counter;
                    if (biggerContainer[mid][0] < smaller[indices[i]][0]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }

                biggerContainer.insert(biggerContainer.begin() + left, smaller[indices[i]]);
                break;
            }
            ++j;
        }
        ++i;
    }
}

template <typename T, typename U>
T PmergeMe::recursionPairing(T& container, T& biggerContainer) {
    if (container.size() == 1)
        return container;

    T bigger;
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

    if (container.size() % 2 == 1) {
        if (level == 1)
            container[i].push_back(-1);
        else
            container[i][level] = -1;
    }

    ++level;
    recursionPairing<T, U>(bigger, biggerContainer);
    --level;

    T smaller;
    
    i = 0;
    while (i < bigger.size()) {
        smaller.push_back(bigger[i]);
        i += 2;
    }
    
    U smallerIndices = generateSequence<U>(smaller.size());

    smaller = reorderSequence<T, U>(smaller, biggerContainer);
    
    if (bigger.size() == 1) {
        biggerContainer.push_back(bigger[0]);
    } else
        bynaryInsertionSort(biggerContainer, smaller, smallerIndices);

    size_t k = 0;
    while (k <= biggerContainer.size() - 1 && biggerContainer[k].size() > 1) {
        biggerContainer[k].pop_back();
        ++k;
    }

    return biggerContainer;
}

template <typename T, typename U>
void PmergeMe::mergeInsert(T& container, T& biggerContainer) {
    counter = 0;
    T sorted;
    T smaller;

    std::cout << "\nBefore: ";
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << (*it)[0] << " ";
    }
    std::cout << "\n" << std::endl;

    sorted = recursionPairing<T, U>(container, biggerContainer);

    size_t i = 0;
    while (i < container.size()) {
        smaller.push_back(container[i]);
        i += 2;
    }

    U smallerIndices = generateSequence<U>(smaller.size());

    smaller = reorderSequence<T, U>(smaller, sorted);

    bynaryInsertionSort(sorted, smaller, smallerIndices);

    std::cout << "After: ";
    for (typename T::iterator it = sorted.begin(); it != sorted.end(); ++it) {
        std::cout << (*it)[0] << " ";
    }
    std::cout << std::endl;
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