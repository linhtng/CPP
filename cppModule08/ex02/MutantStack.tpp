#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack(): std::stack<T, C>() {}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C> &src): std::stack<T, C>(src) {}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

template <typename T, typename C>
MutantStack<T, C> &MutantStack<T, C>::operator=(const MutantStack<T, C> &src)
{
    if (this != &src)
        std::stack<T, C>::operator=(src);
    return *this;
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin()
{
    return std::stack<T, C>::c.begin();
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end()
{
    return std::stack<T, C>::c.end();
}

template <typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::begin() const
{
    return std::stack<T, C>::c.begin();
}

template <typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::end() const
{
    return std::stack<T, C>::c.end();
}

template <typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rBegin()
{
    return std::stack<T, C>::c.rbegin();
}

template <typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rEnd()
{
    return std::stack<T, C>::c.rend();
}

template <typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator MutantStack<T, C>::rBegin() const
{
    return std::stack<T, C>::c.rbegin();
}

template <typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator MutantStack<T, C>::rEnd() const
{
    return std::stack<T, C>::c.rend();
}