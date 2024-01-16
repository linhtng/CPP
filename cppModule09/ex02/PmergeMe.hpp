#include <vector>
#include <list>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <exception>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    std::chrono::duration<double> timeSortVector(std::vector<int> &vec);
    std::chrono::duration<double> timeSortList(std::list<int> &lst);

private:
    std::vector<int> MergeInsertionSort(const std::vector<int> &arr);
    std::list<int> MergeInsertionSort(const std::list<int> &arr);
    std::vector<int> generatePowerSequence(int length);
    std::list<int> generatePowerSequenceList(int length);
};