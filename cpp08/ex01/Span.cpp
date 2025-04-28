#include "Span.hpp"

Span::Span() : _maxSize(0) {}
Span::Span(unsigned int N) : _maxSize(N) {}
Span::Span(const Span &src) : _maxSize(src._maxSize), _numbers(src._numbers) {}
Span::~Span() {}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
        _maxSize = rhs._maxSize;
        _numbers = rhs._numbers;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw FullSpanException();
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
        throw NoSpanException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (span < minSpan)
            minSpan = span;
    }
    
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw NoSpanException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    
    return static_cast<unsigned int>(max - min);
}

const char* Span::FullSpanException::what() const throw()
{
    return "Error: Span is already full";
}

const char* Span::NoSpanException::what() const throw()
{
    return "Error: Cannot find span with less than 2 numbers";
}
