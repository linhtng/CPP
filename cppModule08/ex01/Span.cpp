#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &src) : N(src.N), numbers(src.numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &src)
{
    N = src.N;
    numbers.clear();
    this->addNumbers(src.numbers);
    return *this;
}

void Span::addNumber(int num)
{
    if (numbers.size() >= N)
        throw std::overflow_error("Out of storage space");
    numbers.push_back(num);
}

void Span::addNumbers(const std::vector<int> &srcNums)
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

int Span::shortestSpan() const
{
    int size = numbers.size();
    if (size < 2)
        throw std::runtime_error("404 No span can be found");
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = sortedNumbers[1] - sortedNumbers[0];
    for (int i = 2; i < size; ++i)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("404: No span can be found");

    int maxElem = *std::max_element(numbers.begin(), numbers.end());
    int minElem = *std::min_element(numbers.begin(), numbers.end());
    int longest = maxElem - minElem;
    return longest;
}
