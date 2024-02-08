#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : oddSize(false) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    oddSize = other.oddSize;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printVector(const std::vector<int> &vec)
{
    for (const int &element : vec)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

std::vector<int> PmergeMe::generatePowerSequence(int length)
{
    std::vector<int> sequence;

    int power = 2;
    int sum = 0;
    for (int i = 2; i <= length; i++)
    {
        sequence.push_back(power);
        sum += power;
        if (sum > length)
            break;
        power = std::pow(2, i) - power;
    }

    return sequence;
}

std::list<int> PmergeMe::generatePowerSequenceList(int length)
{
    std::list<int> sequence;

    int power = 2;
    int sum = 0;
    for (int i = 2; i <= length; i++)
    {
        sequence.push_back(power);
        sum += power;
        if (sum > length)
            break;
        power = std::pow(2, i) - power;
    }

    return sequence;
}

std::vector<std::pair<int, int>> PmergeMe::makePairs(const std::vector<int> &vec)
{
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> temp(vec);
    if (oddSize)
        temp.pop_back();
    for (size_t i = 0; i < temp.size() - 1; i += 2)
    {
        std::pair<int, int> pair = std::minmax(temp[i], temp[i + 1]);
        std::swap(pair.first, pair.second);
        pairs.push_back(pair);
    }
    return pairs;
}

std::vector<std::vector<int>> PmergeMe::partition(std::vector<int> &nums, std::vector<int> &groupSizes)
{
    std::vector<std::vector<int>> partitions;
    int start = 0;
    for (int size : groupSizes)
    {
        int end = start + size;
        if (end >= static_cast<int>(nums.size()))
            end = nums.size();
        std::vector<int> partition(nums.begin() + start, nums.begin() + end);
        std::reverse(partition.begin(), partition.end());
        partitions.push_back(partition);
        start += size;
    }
    // std::cout << "Partition start: " << '\n';
    // for (const auto &sub_vector : partitions)
    // {
    //     printVector(sub_vector);
    //     std::cout << "Partition done" << '\n';
    // }
    return partitions;
}

void PmergeMe::MergeInsertionSort(std::vector<int> &vec)
{
    /*
    Step 1+2: Group the elements into pairs and perform (size / 2) comparisons
    to determine the larger element in each pair
    */
    if (vec.size() % 2 != 0)
        oddSize = true;
    std::cout << "Vec size: " << vec.size() << '\n';
    // if (vec.size() <= 1)
    //     return;
    std::vector<std::pair<int, int>> paired = makePairs(vec);

    // Step 3: Sort the larger elements and create a sorted sequence of larger elements in ascending order
    std::sort(paired.begin(), paired.end());
    // MergeInsertionSort(sorted);
    for (const std::pair<int, int> &pair : paired)
    {
        sorted.push_back(pair.second);
        unsorted.push_back(pair.first);
    }
    // MergeInsertionSort(sorted);
    std::cout << "Sorted after each recursive call:\n";
    printVector(sorted);
    if (oddSize)
        unsorted.push_back(vec.back());
    // std::cout << "Sorted atfer step 1 - 3: \n";
    // printVector(sorted);
    // std::cout << "Unsorted: \n";
    // printVector(unsorted);

    // Step 4: Insert the element paired with the smallest element at the start of the sorted sequence
    sorted.insert(sorted.begin(), unsorted.front());
    unsorted.erase(unsorted.begin());
    std::cout << "Unsorted size after step 4:" << unsorted.size() << " \n";
    printVector(unsorted);
    std::cout << "Sorted: ";
    printVector(sorted);
    if (unsorted.empty())
    {
        std::cout << "Unsorted is empty. Returning. \n";
        return;
    }
    // std::cout << "[Vector] Sorted after step 4: \n";
    // printVector(sorted);
    // std::cout << "Unsorted: \n";
    // printVector(unsorted);

    /*
    Step 5 : Partition the unsorted elems into groups with contiguous indexes.
    The sums of sizes of every two adjacent groups form a sequence of powers of two
    */
    // std::cout << "Groups'sized generated so as the sums of sizes of every two adjacent groups form a sequence of powers of two: \n";
    // printVector(groupSizes);
    // std::cout << "Unsorted in groups: \n";
    if (unsorted.size() > 1)
    {
        std::vector<int> groupSizes = generatePowerSequence(unsorted.size());
        std::vector<std::vector<int>> orderToInsert = partition(unsorted, groupSizes);
        // Step 6: Insert the remaining elements into the sorted sequence using binary search
        for (const std::vector<int> &uninsertedGroup : orderToInsert)
        {
            for (const int &element : uninsertedGroup)
            {
                sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), element), element);
            }
        }
    }
    else if (unsorted.size() == 1)
    {
        int elemToInsert = unsorted.front();
        sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), elemToInsert), elemToInsert);
        std::cout << "Sorted after inserting: " << elemToInsert << '\n';
        printVector(sorted);
        return;
    }
}

bool PmergeMe::hasDuplicates(const std::vector<int> &vec)
{
    std::unordered_set<int> set(vec.begin(), vec.end());
    return set.size() != vec.size();
}

void PmergeMe::printTime(const std::chrono::high_resolution_clock::duration &duration, int sequenceLen, const std::string &type)
{
    long long time_in_us = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    std::cout << "Time to process a range of " << sequenceLen << " elements with "
              << type << ": " << time_in_us << " us\n";
}

void PmergeMe::timeSortVector(int argc, char *argv[])
{
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::vector<int> vec;
    for (int i = 1; i < argc; ++i)
    {
        int num = std::stoi(argv[i]);
        if (num <= 0)
        {
            throw std::invalid_argument("Error");
        }
        vec.push_back(num);
    }
    // if (hasDuplicates(vec))
    // {
    //     std::cout << "Duplicates found.\n";
    //     throw std::invalid_argument("Error");
    // }
    MergeInsertionSort(vec);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::cout << "After: ";
    printVector(sorted);
    printTime(end - start, argc - 1, "std::vector");
}

void PmergeMe::printList(const std::list<int> &lst)
{
    for (const int &element : lst)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

std::list<std::pair<int, int>> PmergeMe::makePairs(const std::list<int> &lst)
{
    std::list<std::pair<int, int>> pairs;
    std::list<int> temp(lst);
    if (oddSize)
        temp.pop_back();
    for (std::list<int>::iterator it = temp.begin(); it != temp.end(); std::advance(it, 2))
    {
        std::pair<int, int> pair = std::minmax(*it, *std::next(it));
        std::swap(pair.first, pair.second);
        pairs.push_back(pair);
    }
    return pairs;
}

std::list<std::list<int>> PmergeMe::partition(std::list<int> &nums, std::list<int> &groupSizes)
{
    std::list<std::list<int>> partitions;
    std::list<int>::iterator start = nums.begin();
    for (int size : groupSizes)
    {
        std::list<int>::iterator end = start;
        std::advance(end, std::min(size, static_cast<int>(std::distance(start, nums.end()))));
        std::list<int> partition(start, end);
        partition.reverse();
        partitions.push_back(partition);
        std::advance(start, size);
    }
    // std::cout << "Partition start" << '\n';
    // for (const auto &sub_list : partitions)
    // {
    //     printList(sub_list);
    //     std::cout << "Partition done" << '\n';
    // }
    return partitions;
}

int PmergeMe::binarySearchList(std::list<int> &subsequence, int left, int right, int elemToInsert)
{
    if (right <= left)
        return (elemToInsert > *std::next(subsequence.begin(), left)) ? (left + 1) : left;
    int mid = (left + right) / 2;
    if (elemToInsert > *std::next(subsequence.begin(), mid))
        return binarySearchList(subsequence, mid + 1, right, elemToInsert);
    return binarySearchList(subsequence, left, mid - 1, elemToInsert);
}

/*
This function first find a subsequence of the sorted list that contains the elements up to the
lowerbound of the elemToInsert. It then performs a binary search on that subsequence to find the location
to insert the element.
*/
void PmergeMe::binaryInsertionSortList(std::list<int> &mainChain, int elemToInsert)
{
    std::list<int>::iterator it = list_lower_bound(mainChain, elemToInsert);
    if (it != mainChain.begin())
    {
        std::list<int> subsequence(mainChain.begin(), it);
        int location = binarySearchList(subsequence, 0, subsequence.size() - 1, elemToInsert);
        sortedList.insert(std::next(sortedList.begin(), location), elemToInsert);
    }
    else
    {
        sortedList.insert(sortedList.begin(), elemToInsert);
    }
    // std::cout << "Subsequence to insert: \n";
    // printList(subsequenceToInsert);
    // std::cout << "Location: " << location << "\n";
    // std::cout << "\nSorted after inserting:" << elemToInsert << "\n";
    // printList(sortedList);
}

std::list<int>::iterator PmergeMe::list_lower_bound(std::list<int> &lst, const int &value)
{
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end() && *it < value)
    {
        ++it;
    }
    return it;
}

void PmergeMe::MergeInsertionSort(std::list<int> &lst)
{
    // Step 1+2: Group the elements into pairs and perform comparisons to determine the larger element in each pair
    if (lst.size() % 2 != 0)
        oddSize = true;
    std::list<std::pair<int, int>> paired = makePairs(lst);
    // Step 3: Sort the larger elements and create a sorted sequence of larger elements in ascending order
    paired.sort();
    for (const std::pair<int, int> &pair : paired)
    {
        sortedList.push_back(pair.first);
        unsortedList.push_back(pair.second);
    }
    if (oddSize)
        unsortedList.push_back(lst.back());
    // std::cout << "Sorted after step 1 - 3: \n";
    // printList(sortedList);
    // std::cout << "Unsorted: \n";
    // printList(unsortedList);

    // Step 4: Insert the element paired with the smallest element at the start of the sorted sequence
    sortedList.insert(sortedList.begin(), unsortedList.front());
    unsortedList.erase(unsortedList.begin());
    // std::cout << "[List] Sorted after step 4: \n";
    // printList(sortedList);
    // std::cout << "Unsorted: \n";
    // printList(unsortedList);

    /*
    Step 5 : Partition the unsorted elems into groups with contiguous indexes.
    The sums of sizes of every two adjacent groups form a sequence of powers of two
    */
    std::list<int> groupSizes = generatePowerSequenceList(unsortedList.size());
    // printList(groupSizes);
    // std::cout << "Unsorted in partitioned groups: \n";
    std::list<std::list<int>> orderToInsert = partition(unsortedList, groupSizes);

    /*
    Step 6: Insert the remaining elements into the sorted sequence using binary search
    First, find the length of the subsequence to insert the element into
    As we are inserting in order y_4, y_3, y_6, y_5, y_12, y_11, y_10, y_9, y_8, y_7, y_22, y_21...
    The subsequence length is to insert will be up to but not including x_i.
    We then perform a binary search on that subsequence to find the location to insert the element.
    */
    for (const std::list<int> &uninsertedGroup : orderToInsert)
    {
        for (const int &element : uninsertedGroup)
        {
            binaryInsertionSortList(sortedList, element);
        }
    }
}

bool PmergeMe::hasDuplicates(const std::list<int> &lst)
{
    std::unordered_set<int> set(lst.begin(), lst.end());
    return set.size() != lst.size();
}

void PmergeMe::sortListTest()
{
    std::cout << "sortList Test: ";
    if (std::is_sorted(sortedList.begin(), sortedList.end()))
        std::cout << CYAN "Sorted\n" RESET;
    else
        std::cout << RED "Not sorted\n" RESET;
}

void PmergeMe::sortVectorTest()
{
    std::cout << "sortVector Test: ";
    if (std::is_sorted(sorted.begin(), sorted.end()))
        std::cout << CYAN "Sorted\n" RESET;
    else
        std::cout << RED "Not sorted\n" RESET;
}

void PmergeMe::timeSortList(int argc, char *argv[])
{
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::list<int> lst;
    for (int i = 1; i < argc; ++i)
    {
        int num = std::stoi(argv[i]);
        if (num <= 0)
        {
            throw std::invalid_argument("Error");
        }
        lst.push_back(num);
    }
    // if (hasDuplicates(lst))
    // {
    //     throw std::invalid_argument("Error");
    // }
    MergeInsertionSort(lst);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // std::cout << "After: ";
    // printList(sortedList);
    printTime(end - start, argc - 1, "std::list");
}