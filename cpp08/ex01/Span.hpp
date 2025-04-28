#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &src);
    ~Span();

    Span &operator=(const Span &rhs);

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end);
    
    class FullSpanException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    unsigned int count = 0;
    Iterator it = begin;
    
    while (it != end)
    {
        count++;
        ++it;
    }
    
    if (_numbers.size() + count > _maxSize)
        throw FullSpanException();
    
    _numbers.insert(_numbers.end(), begin, end);
}

#endif
