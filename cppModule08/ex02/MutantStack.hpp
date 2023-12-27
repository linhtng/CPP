#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>
#include <iterator>

#define RED "\e[91m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack &src);
    MutantStack &operator=(const MutantStack &src);
    ~MutantStack();

    /* Define the iterator type explicitly */
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;
};

// Include the template implementation
#include "MutantStack.tpp"

#endif