#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>

class PmergeMe {
private:
    std::vector<std::vector<int> > vector;
    std::deque<std::deque<int> > deque;
    std::vector<int> indexes;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe();
    
    void generateSequence(void);
};

#endif // PmergeMe.hpp