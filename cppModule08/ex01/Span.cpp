#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &src)
{
    *this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src)
{
    N = src.getMaxSize();
    return *this;
}

unsigned int Span::getMaxSize() const
{
    return N;
}

void Span::addNumber(int num)
{
    if (numbers.size() >= N)
        throw std::overflow_error("Out of storage space");
    numbers.push_back(num);
}

void Span::addNumber(const std::vector<int> &srcNums)
{
    if (numbers.size() + srcNums.size() > N)
        throw std::overflow_error("Out of storage space");
    std::copy(srcNums.begin(), srcNums.end(), back_inserter(numbers));
}

void Span::showContains()
{
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}