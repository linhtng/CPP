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

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
public:
    MutantStack();
    MutantStack(const MutantStack &src);
    MutantStack &operator=(const MutantStack &src);
    ~MutantStack();

    /* Define the iterator type explicitly */
    typedef typename std::stack<T, C>::container_type::iterator iterator;
    typedef typename std::stack<T, C>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T, C>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T, C>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rBegin();
    reverse_iterator rEnd();
    const_reverse_iterator rBegin() const;
    const_reverse_iterator rEnd() const;
};

// Include the template implementation
#include "MutantStack.tpp"

#endif