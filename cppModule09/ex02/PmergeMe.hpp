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
    void printVector(const std::vector<int> &vec);

private:
    // std::vector<int> MergeInsertionSort(const std::vector<int> &arr);
    void MergeInsertionSort(std::vector<int> &vec);
    std::list<int> MergeInsertionSort(const std::list<int> &arr);
    std::vector<int> generatePowerSequence(int length);
    std::list<int> generatePowerSequenceList(int length);
    std::vector<std::pair<int, int>> makePairs(const std::vector<int> &vec);
    std::vector<std::vector<int>> partition(std::vector<int> &nums, std::vector<int> &groupSizes);
    std::vector<int> binarySearchLength(const std::vector<int> &vec);
    void binaryInsertionSort(std::vector<int> &subsequence, int elemToInsert);
    int binarySearch(std::vector<int> &subsequence, int left, int right, int elemToInsert);
    std::vector<int> findSubsequence(const std::vector<int> &newSequence, int rightmostValue);

    std::vector<int> sorted;
    std::vector<int> unsorted;
    bool oddSize;
};