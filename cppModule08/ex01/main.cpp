#include <iterator>
#include "Span.hpp"
#include <list>

#define RED "\e[91m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

int main()
{
    Span sp = Span(10);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::vector<int> foo;
    for (int i = 1; i <= 5; i++)
        foo.push_back(i * 10);
    sp.addNumber(foo);
    sp.showContains();
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    return 0;
}