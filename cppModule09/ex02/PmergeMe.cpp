#include "PmergeMe.hpp"

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

std::deque<int> PmergeMe::generatePowerSequencedeque(int length)
{
    std::deque<int> sequence;

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
    for (size_t i = 0; i < vec.size() - 1; i += 2)
    {
        std::pair<int, int> pair = std::minmax(vec[i], vec[i + 1]);
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
    // Step 1+2: Group the elements into pairs and perform comparisons to determine the larger element in each pair
    if (vec.size() <= 1)
        return;
    bool oddSize = false;
    int lastElement = 0;
    if (vec.size() % 2 != 0)
    {
        oddSize = true;
        lastElement = vec.back();
        vec.pop_back(); // Remove the last element
    }
    std::vector<std::pair<int, int>> paired = makePairs(vec);

    /* Step 3: Recursively sort the larger elements and create a sorted sequence
    of larger elements in ascending order */
    sorted.clear();
    for (const std::pair<int, int> &pair : paired)
    {
        sorted.push_back(pair.second);
    }
    // Create a map from the pairs
    std::unordered_map<int, int> pairMap;
    for (const std::pair<int, int> &pair : paired)
    {
        pairMap[pair.second] = pair.first;
    }
    MergeInsertionSort(sorted);
    unsorted.clear();
    if (paired.size() > 1)
    {
        for (const int &element : sorted) // complexity O(n)
        {
            std::unordered_map<int, int>::iterator it = pairMap.find(element);
            if (it != pairMap.end())
                unsorted.push_back(it->second);
        }
    }
    else
    {
        unsorted.push_back(paired.front().first);
    }
    if (oddSize)
        unsorted.push_back(lastElement);
    // std::cout << "Sorted atfer step 1 - 3: \n";
    // printVector(sorted);
    // std::cout << "Unsorted: \n";
    // printVector(unsorted);

    // Step 4: Insert the element paired with the smallest element at the start of the sorted sequence
    sorted.insert(sorted.begin(), unsorted.front());
    unsorted.erase(unsorted.begin());
    // std::cout << "[Vector] Sorted after step 4: \n";
    // printVector(sorted);
    // std::cout << "Unsorted: \n";
    // printVector(unsorted);

    /*
    Step 5 : Partition the unsorted elems into groups with contiguous indexes.
    The sums of sizes of every two adjacent groups form a sequence of powers of two
    */
    if (unsorted.size() > 1)
    {
        std::vector<int> groupSizes = generatePowerSequence(unsorted.size());
        // std::cout << "Groups'sized generated so as the sums of sizes of every two adjacent groups form a sequence of powers of two: \n";
        // printVector(groupSizes);
        // std::cout << "Unsorted in groups: \n";
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

void PmergeMe::printdeque(const std::deque<int> &dequ)
{
    for (const int &element : dequ)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

std::deque<std::pair<int, int>> PmergeMe::makePairs(const std::deque<int> &dequ)
{
    std::deque<std::pair<int, int>> pairs;
    for (size_t i = 0; i < dequ.size() - 1; i += 2)
    {
        std::pair<int, int> pair = std::minmax(dequ[i], dequ[i + 1]);
        pairs.push_back(pair);
    }
    return pairs;
}

std::deque<std::deque<int>> PmergeMe::partition(std::deque<int> &nums, std::deque<int> &groupSizes)
{
    std::deque<std::deque<int>> partitions;
    std::deque<int>::iterator start = nums.begin();
    for (int size : groupSizes)
    {
        std::deque<int>::iterator end = start;
        std::advance(end, std::min(size, static_cast<int>(std::distance(start, nums.end()))));
        std::deque<int> partition(start, end);
        // partition.reverse();
        partitions.push_back(partition);
        std::advance(start, size);
    }
    // std::cout << "Partition start" << '\n';
    // for (const auto &sub_deque : partitions)
    // {
    //     printdeque(sub_deque);
    //     std::cout << "Partition done" << '\n';
    // }
    return partitions;
}

int PmergeMe::binarySearchdeque(std::deque<int> &subsequence, int left, int right, int elemToInsert)
{
    if (right <= left)
        return (elemToInsert > *std::next(subsequence.begin(), left)) ? (left + 1) : left;
    int mid = (left + right) / 2;
    if (elemToInsert > *std::next(subsequence.begin(), mid))
        return binarySearchdeque(subsequence, mid + 1, right, elemToInsert);
    return binarySearchdeque(subsequence, left, mid - 1, elemToInsert);
}

/*
This function first find a subsequence of the sorted deque that contains the elements up to the
lowerbound of the elemToInsert. It then performs a binary search on that subsequence to find the location
to insert the element.
*/
void PmergeMe::binaryInsertionSortdeque(std::deque<int> &mainChain, int elemToInsert)
{
    std::deque<int>::iterator it = deque_lower_bound(mainChain, elemToInsert);
    if (it != mainChain.begin())
    {
        std::deque<int> subsequence(mainChain.begin(), it);
        int location = binarySearchdeque(subsequence, 0, subsequence.size() - 1, elemToInsert);
        sorteddeque.insert(std::next(sorteddeque.begin(), location), elemToInsert);
    }
    else
    {
        sorteddeque.insert(sorteddeque.begin(), elemToInsert);
    }
    // std::cout << "Subsequence to insert: \n";
    // printdeque(subsequenceToInsert);
    // std::cout << "Location: " << location << "\n";
    // std::cout << "\nSorted after inserting:" << elemToInsert << "\n";
    // printdeque(sorteddeque);
}

std::deque<int>::iterator PmergeMe::deque_lower_bound(std::deque<int> &dequ, const int &value)
{
    std::deque<int>::iterator it = dequ.begin();
    while (it != dequ.end() && *it < value)
    {
        ++it;
    }
    return it;
}

void PmergeMe::MergeInsertionSort(std::deque<int> &dequ)
{
    // Step 1+2: Group the elements into pairs and perform comparisons to determine the larger element in each pair
    if (dequ.size() <= 1)
        return;
    bool oddSize = false;
    int lastElement = 0;
    if (dequ.size() % 2 != 0)
    {
        oddSize = true;
        lastElement = dequ.back();
        dequ.pop_back(); // Remove the last element
    }
    std::deque<std::pair<int, int>> paired = makePairs(dequ);
    for (const std::pair<int, int> &pair : paired)
    {
        std::cout << "Pair: " << pair.first << " " << pair.second << '\n';
    }
    // Step 3: Sort the larger elements and create a sorted sequence of larger elements in ascending order
    // paired.sort();
    for (const std::pair<int, int> &pair : paired)
    {
        sorteddeque.push_back(pair.first);
        unsorteddeque.push_back(pair.second);
    }
    if (oddSize)
        unsorteddeque.push_back(dequ.back());
    // std::cout << "Sorted after step 1 - 3: \n";
    // printdeque(sorteddeque);
    // std::cout << "Unsorted: \n";
    // printdeque(unsorteddeque);

    // Step 4: Insert the element paired with the smallest element at the start of the sorted sequence
    sorteddeque.insert(sorteddeque.begin(), unsorteddeque.front());
    unsorteddeque.erase(unsorteddeque.begin());
    // std::cout << "[deque] Sorted after step 4: \n";
    // printdeque(sorteddeque);
    // std::cout << "Unsorted: \n";
    // printdeque(unsorteddeque);

    /*
    Step 5 : Partition the unsorted elems into groups with contiguous indexes.
    The sums of sizes of every two adjacent groups form a sequence of powers of two
    */
    std::deque<int> groupSizes = generatePowerSequencedeque(unsorteddeque.size());
    // printdeque(groupSizes);
    // std::cout << "Unsorted in partitioned groups: \n";
    std::deque<std::deque<int>> orderToInsert = partition(unsorteddeque, groupSizes);

    /*
    Step 6: Insert the remaining elements into the sorted sequence using binary search
    First, find the length of the subsequence to insert the element into
    As we are inserting in order y_4, y_3, y_6, y_5, y_12, y_11, y_10, y_9, y_8, y_7, y_22, y_21...
    The subsequence length is to insert will be up to but not including x_i.
    We then perform a binary search on that subsequence to find the location to insert the element.
    */
    for (const std::deque<int> &uninsertedGroup : orderToInsert)
    {
        for (const int &element : uninsertedGroup)
        {
            binaryInsertionSortdeque(sorteddeque, element);
        }
    }
}

bool PmergeMe::hasDuplicates(const std::deque<int> &dequ)
{
    std::unordered_set<int> set(dequ.begin(), dequ.end());
    return set.size() != dequ.size();
}

void PmergeMe::sortdequeTest()
{
    std::cout << "sortdeque Test: ";
    if (std::is_sorted(sorteddeque.begin(), sorteddeque.end()))
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

void PmergeMe::timeSortDeque(int argc, char *argv[])
{
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::deque<int> dequ;
    for (int i = 1; i < argc; ++i)
    {
        int num = std::stoi(argv[i]);
        if (num <= 0)
        {
            throw std::invalid_argument("Error");
        }
        dequ.push_back(num);
    }
    // if (hasDuplicates(dequ))
    // {
    //     throw std::invalid_argument("Error");
    // }
    MergeInsertionSort(dequ);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // std::cout << "After: ";
    // printdeque(sorteddeque);
    printTime(end - start, argc - 1, "std::deque");
}