#include <vector>
#include <list>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <unordered_set>

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
    void timeSortList(int argc, char *argv[]);
    void printVector(const std::vector<int> &vec);
    void printList(const std::list<int> &lst);
    void sortVectorTest();
    void sortListTest();

private:
    void MergeInsertionSort(std::vector<int> &vec);
    void MergeInsertionSort(std::list<int> &lst);

    std::vector<int> generatePowerSequence(int length);
    std::list<int> generatePowerSequenceList(int length);

    std::vector<std::pair<int, int>> makePairs(const std::vector<int> &vec);
    std::list<std::pair<int, int>> makePairs(const std::list<int> &lst);

    std::vector<std::vector<int>> partition(std::vector<int> &nums, std::vector<int> &groupSizes);
    std::list<std::list<int>> partition(std::list<int> &nums, std::list<int> &groupSizes);

    std::vector<int> binarySearchLength(const std::vector<int> &vec);
    std::list<int> binarySearchLength(const std::list<int> &lst);

    void binaryInsertionSort(std::vector<int> &subsequence, int elemToInsert);
    void binaryInsertionSortList(std::list<int> &subsequenceToInsert, int elemToInsert);

    int binarySearch(std::vector<int> &subsequence, int left, int right, int elemToInsert);
    int binarySearchList(std::list<int> &subsequence, int left, int right, int elemToInsert);

    std::vector<int> findSubsequence(const std::vector<int> &newSequence, int upperBound);
    std::list<int> findSubsequence(const std::list<int> &newSequence, const std::list<int> &oldSequence, int upperBound);

    std::list<int>::iterator list_lower_bound(std::list<int> &lst, const int &value);

    bool hasDuplicates(const std::vector<int> &vec);
    bool hasDuplicates(const std::list<int> &lst);
    void printTime(const std::chrono::high_resolution_clock::duration &duration, int sequenceLen, const std::string &type);

    std::vector<int> sorted;
    std::vector<int> unsorted;

    std::list<int> sortedList;
    std::list<int> unsortedList;
    bool oddSize;
};