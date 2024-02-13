#include <vector>
#include <deque>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <iterator>
#include <unordered_map>
#include <utility> // for std::pair

#define RED "\e[91m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void timeSortVector(int argc, char *argv[]);
    void timeSortDeque(int argc, char *argv[]);
    void printVector(const std::vector<int> &vec);
    void printdeque(const std::deque<int> &lst);
    void sortVectorTest();
    void sortdequeTest();

private:
    void MergeInsertionSort(std::vector<int> &vec);
    void MergeInsertionSort(std::deque<int> &lst);

    std::vector<int> generatePowerSequence(int length);
    std::deque<int> generatePowerSequencedeque(int length);

    std::vector<std::pair<int, int>> makePairs(const std::vector<int> &vec);
    std::deque<std::pair<int, int>> makePairs(const std::deque<int> &lst);

    std::vector<std::vector<int>> partition(std::vector<int> &nums, std::vector<int> &groupSizes);
    std::deque<std::deque<int>> partition(std::deque<int> &nums, std::deque<int> &groupSizes);

    std::deque<int> binarySearchLength(const std::deque<int> &lst);

    void binaryInsertionSortdeque(std::deque<int> &subsequenceToInsert, int elemToInsert);

    int binarySearchdeque(std::deque<int> &subsequence, int left, int right, int elemToInsert);

    std::deque<int> findSubsequence(const std::deque<int> &newSequence, const std::deque<int> &oldSequence, int upperBound);

    std::deque<int>::iterator deque_lower_bound(std::deque<int> &lst, const int &value);

    bool hasDuplicates(const std::vector<int> &vec);
    bool hasDuplicates(const std::deque<int> &lst);
    void printTime(const std::chrono::high_resolution_clock::duration &duration, int sequenceLen, const std::string &type);

    std::vector<int> sorted;
    std::vector<int> unsorted;

    std::deque<int> sorteddeque;
    std::deque<int> unsorteddeque;
};