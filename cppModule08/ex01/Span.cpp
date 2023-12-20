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
    (void)src;
    return *this;
}