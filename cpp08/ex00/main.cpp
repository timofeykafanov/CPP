#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    
    std::cout << std::endl << "===== Test with vector =====" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== Test with list =====" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << std::endl << "===== Test with deque =====" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);
    deq.push_back(500);

    try {
        std::deque<int>::iterator it = easyfind(deq, 200);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
