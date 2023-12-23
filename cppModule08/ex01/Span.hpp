#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

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

    unsigned int getMaxSize() const;
    void addNumber(int num);
    void addNumber(const std::vector<int> &numbers);
    void showContains();
};

#endif