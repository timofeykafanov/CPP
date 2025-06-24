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
    std::cout << "\nRecursion level: " << level << "  +++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
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
    recursionPairing(bigger, biggerContainer, indices);
    --level;

    std::cout << "\nRecursion level: " << level << "  -----------------------------------------------------" << std::endl;

    T smaller;
    
    i = 0;
    while (i < bigger.size()) {
        smaller.push_back(bigger[i]);
        i += 2;
    }
    
    U smallerIndices = generateSequence<U>(smaller.size());
    
    size_t size = biggerContainer.size();

    std::cout << "\nsmallerIndices: ";
    for (typename U::iterator it = smallerIndices.begin(); it != smallerIndices.end(); ++it) {
        std::cout << *it;
        if (it + 1 != smallerIndices.end())
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "\nsmaller: ";
    for (typename T::iterator it = smaller.begin(); it != smaller.end(); ++it) {
        std::cout << "[";
        for (typename T::value_type::iterator jt = it->begin(); jt != it->end(); ++jt) {
            std::cout << *jt;
            if (jt + 1 != it->end())
                std::cout << " ";
        }
        std::cout << "]";
        if (it + 1 != smaller.end())
            std::cout << " ";
    }
    std::cout << std::endl;

    if (bigger.size() == 1) {
        biggerContainer.push_back(bigger[0]);
    } else {
        i = 0;
        while (i < smaller.size()) {
            size_t j = 0;
            while (j < biggerContainer.size()) {
                std::cout << "Condition:" << (smaller.size() > size && i == smaller.size() - 1) << std::endl;
                if (smaller[smallerIndices[i]].back() == biggerContainer[j].back()
                    || (smaller.size() > size && smallerIndices[i] == (int)smaller.size() - 1)) {
                    std::cout << "Inserting smaller[" << smaller[smallerIndices[i]][0] << "] into biggerContainer at position " << j << " ; i = " << i <<  std::endl;
                    size_t left = 0;
                    size_t right = j;
                    if (smaller.size() > size && i == smaller.size() - 1)
                        right = biggerContainer.size() - 1;
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

    std::cout << "\nbiggerContainer 2: ";
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

    return biggerContainer;
}

template <typename T, typename U>
void PmergeMe::mergeInsert(T& container, T& biggerContainer, U &indices) {
    counter = 0;
    T bigger;
    T smaller;
    bigger = recursionPairing(container, biggerContainer, indices);

    size_t i = 0;
    while (i < container.size()) {
        smaller.push_back(container[i]);
        i += 2;
    }

    i = 0;
    while (i <= smaller.size() - 1) {
        std::cout << "\nInserting smaller[" << smaller[indices[i]][0] << "] = ";
        size_t j = 0;
        while (j < bigger.size()) {
            if (bigger[j][1] == smaller[indices[i]][1]) {
                size_t left = 0;
                size_t right = j;
                while (left < right) {
                    size_t mid = left + (right - left) / 2;
                    ++counter;
                    if (bigger[mid][0] < smaller[indices[i]][0]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }

                bigger.insert(bigger.begin() + left, smaller[indices[i]]);
                break;
            }
            ++j;
        }
        ++i;
    }

    std::cout << "\nFinal sequence: ";
    for (typename T::iterator it = bigger.begin(); it != bigger.end(); ++it) {
        std::cout << (*it)[0] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nInitial length: " << container.size() << std::endl;
    std::cout << "\nFinal length: " << bigger.size() << std::endl;

    std::cout << "\nNumber of comparisons: " << counter << std::endl;
}

template <typename Out>
Out PmergeMe::generateSequence(size_t length) {
    Out indices;
    if (length == 1) {
        indices.push_back(0); // Return sequence with a single element 0
        return indices;
    }
    // size_t n = length;
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

    return indices;
}

#endif // PmergeMe.hpp