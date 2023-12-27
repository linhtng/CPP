#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>

#define RED "\e[91m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

class Span
{
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &src);
    Span &operator=(const Span &src);
    ~Span();

    void addNumber(int num);
    void addNumbers(const std::vector<int> &numbers);
    int longestSpan() const;
    int shortestSpan() const;
    void showContains();
};

#endif