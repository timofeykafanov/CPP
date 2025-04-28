#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

void basicTest()
{
    std::cout << "===== BASIC TEST =====" << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void exceptionTest()
{
    std::cout << "\n===== EXCEPTION TEST =====" << std::endl;
    
    try
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        Span sp(5);
        sp.addNumber(1);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        Span sp(5);
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void largeSpanTest()
{
    std::cout << "\n===== LARGE SPAN TEST (10,000 numbers) =====" << std::endl;
    
    Span largeSpan(10000);
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    for (int i = 0; i < 10000; ++i)
    {
        largeSpan.addNumber(rand());
    }
    
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
}

void iteratorRangeTest()
{
    std::cout << "\n===== RANGE TEST =====" << std::endl;
    
    std::list<int> numbers;
    for (int i = 1; i <= 5; ++i)
        numbers.push_back(i * 10);
    
    Span sp1(10);
    sp1.addRange(numbers.begin(), numbers.end());
    
    std::cout << "After adding range {10, 20, 30, 40, 50}:" << std::endl;
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    
    std::vector<int> vec;
    for (int i = 0; i < 100; ++i)
        vec.push_back(i);
    
    Span sp2(100);
    sp2.addRange(vec.begin(), vec.end());
    
    std::cout << "\nAfter adding range from 0 to 99:" << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    
    try
    {
        Span sp3(10);
        std::vector<int> bigVec(20, 1);
        sp3.addRange(bigVec.begin(), bigVec.end());
    }
    catch (const std::exception& e)
    {
        std::cout << "\nException caught when adding too many elements: " << e.what() << std::endl;
    }
}

int main()
{
    basicTest();
    exceptionTest();
    largeSpanTest();
    iteratorRangeTest();
    
    return 0;
}
