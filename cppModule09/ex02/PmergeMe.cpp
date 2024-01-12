#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int> &vec)
{
    std::sort(vec.begin(), vec.end());
}

void PmergeMe::sortList(std::list<int> &lst)
{
    lst.sort();
}

std::chrono::duration<double> PmergeMe::timeSortVector(std::vector<int> &vec)
{
    auto start = std::chrono::high_resolution_clock::now();
    sortVector(vec);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}

std::chrono::duration<double> PmergeMe::timeSortList(std::list<int> &lst)
{
    auto start = std::chrono::high_resolution_clock::now();
    sortList(lst);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}