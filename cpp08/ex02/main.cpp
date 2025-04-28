#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

void testMutantStack()
{
    std::cout << "===== TESTING MUTANTSTACK =====" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Elements (from begin to end):" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << "Creating a standard stack from MutantStack" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "New stack size: " << s.size() << std::endl;
    std::cout << "New stack top: " << s.top() << std::endl;
}

void testList()
{
    std::cout << "\n===== TESTING LIST =====" << std::endl;
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << "Back: " << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << "Size: " << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "Elements (from begin to end):" << std::endl;
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void testReverseIterators()
{
    std::cout << "\n===== TESTING REVERSE ITERATORS =====" << std::endl;
    MutantStack<int> mstack;
    
    for (int i = 1; i <= 5; ++i)
        mstack.push(i * 10);
    
    std::cout << "Elements (from rbegin to rend):" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
}

void testConstIterators()
{
    std::cout << "\n===== TESTING CONST ITERATORS =====" << std::endl;
    MutantStack<int> mstack;
    
    for (int i = 1; i <= 5; ++i)
        mstack.push(i);
    
    const MutantStack<int> constStack(mstack);
    
    std::cout << "Elements of const stack:" << std::endl;
    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();
    
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
}

void testDifferentTypes()
{
    std::cout << "\n===== TESTING WITH DIFFERENT TYPES =====" << std::endl;
    
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("42");
    
    std::cout << "String stack elements:" << std::endl;
    MutantStack<std::string>::iterator sit = strStack.begin();
    MutantStack<std::string>::iterator site = strStack.end();
    
    while (sit != site)
    {
        std::cout << *sit << std::endl;
        ++sit;
    }
}

int main()
{
    testMutantStack();
    testList();
    testReverseIterators();
    testConstIterators();
    testDifferentTypes();
    
    return 0;
}
