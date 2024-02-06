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
    for (const auto &element : vec)
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
        if (temp[i] > temp[i + 1])
            pairs.emplace_back(temp[i], temp[i + 1]);
        else
            pairs.emplace_back(temp[i + 1], temp[i]);
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
    for (const auto &sub_vector : partitions)
    {
        printVector(sub_vector);
        std::cout << "Partition done" << '\n';
    }
    return partitions;
}

std::vector<int> PmergeMe::binarySearchLength(const std::vector<int> &groupSizes)
{
    std::vector<int> result;
    int index = 2;
    for (const auto &size : groupSizes)
    {
        index += size;
        for (int i = 0; i < size; i++)
        {
            result.push_back(index - i - 2);
        }
    }
    return result;
}

int PmergeMe::binarySearch(std::vector<int> &subsequence, int left, int right, int elemToInsert)
{
    if (right <= left)
        return (elemToInsert > subsequence[left]) ? (left + 1) : left;
    int mid = (left + right) / 2;
    if (elemToInsert > subsequence[mid])
        return binarySearch(subsequence, mid + 1, right, elemToInsert);
    return binarySearch(subsequence, left, mid - 1, elemToInsert);
}

void PmergeMe::binaryInsertionSort(std::vector<int> &subsequenceToInsert, int elemToInsert)
{
    // std::vector<int> subsequenceToInsert(sorted.begin(), sorted.begin() + searchLength);
    // std::vector<int> subsequenceToInsert = findSubsequence(sorted, sorted[searchLength - 1]);
    std::cout << "Subsequence to insert: \n";
    printVector(subsequenceToInsert);
    int location = binarySearch(subsequenceToInsert, 0, subsequenceToInsert.size() - 1, elemToInsert);
    std::cout << "Location: " << location << "\n";
    sorted.insert(sorted.begin() + location, elemToInsert);
    std::cout << "\nSorted after inserting:" << elemToInsert << "\n";
    printVector(sorted);
    // sorted.insert(sorted.begin() + lowerBound, elemToInsert);
}

std::vector<int> PmergeMe::findSubsequence(const std::vector<int> &newSequence, int upperBound)
{
    // Find the location of the upperBound value in the new sequence
    auto it = std::find(newSequence.begin(), newSequence.end(), upperBound);

    // Create a subsequence from the beginning of the new sequence to the location of the upperBound value
    std::vector<int> subsequence(newSequence.begin(), it + 1);
    std::cout << "Subsequence with upperBound " << upperBound << ": \n";
    return subsequence;
}

void PmergeMe::MergeInsertionSort(std::vector<int> &vec)
{
    // Step 1+2: Group the elements into pairs and perform comparisons to determine the larger element in each pair
    if (vec.size() % 2 != 0)
        oddSize = true;
    std::vector<std::pair<int, int>> paired = makePairs(vec);

    // Step 3: Sort the larger elements and create a sorted sequence of larger elements in ascending order
    std::sort(paired.begin(), paired.end());
    for (const auto &pair : paired)
    {
        sorted.push_back(pair.first);
        unsorted.push_back(pair.second);
    }
    if (oddSize)
        unsorted.push_back(vec.back());
    std::cout << "Sorted: \n";
    printVector(sorted);
    std::cout << "Unsorted: \n";
    printVector(unsorted);

    // Step 4: Insert the element paired with the smallest element at the start of the sorted sequence
    sorted.insert(sorted.begin(), unsorted.front());
    unsorted.erase(unsorted.begin());
    std::cout << "Sorted: \n";
    printVector(sorted);
    std::cout << "Unsorted: \n";
    printVector(unsorted);

    /*
    Step 5 : Partition the unsorted elems into groups with contiguous indexes.
    The sums of sizes of every two adjacent groups form a sequence of powers of two
    */
    std::vector<int> groupSizes = generatePowerSequence(unsorted.size());
    printVector(groupSizes);
    std::cout << "Unsorted in groups: \n";
    std::vector<std::vector<int>> orderToInsert = partition(unsorted, groupSizes);
    // Step 6: Insert the remaining elements into the sorted sequence using binary search
    std::vector<int> subsequenceLength = binarySearchLength(groupSizes);
    std::cout << "Subsequence length: \n";
    printVector(subsequenceLength);
    std::vector<int> originalSorted = sorted;
    for (const auto &uninsertedGroup : orderToInsert)
    {
        for (const auto &element : uninsertedGroup)
        {
            std::vector<int> subsequence = findSubsequence(sorted, originalSorted[subsequenceLength[0]]);
            binaryInsertionSort(subsequence, element);
            subsequenceLength.erase(subsequenceLength.begin());
        }
        std::cout << '\n';
    }
    if (std::is_sorted(sorted.begin(), sorted.end()))
        std::cout << "Sorted\n";
    else
        std::cout << "Not sorted\n";
    // for (const auto &element : insertion_order)
    // {
    //     auto it = std::lower_bound(sorted_elements.begin(), sorted_elements.end(), element);
    //     sorted_elements.insert(it, element);
    // }

    // return sorted_elements;
}

bool PmergeMe::hasDuplicates(const std::vector<int> &vec)
{
    std::unordered_set<int> set(vec.begin(), vec.end());
    return set.size() != vec.size();
}

void PmergeMe::printTime(const std::chrono::high_resolution_clock::duration &duration, int sequenceLen, const std::string &type)
{
    auto time_in_us = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    std::cout << "Time to process a range of " << sequenceLen << " elements with "
              << type << ": " << time_in_us << " us\n";
}

void PmergeMe::timeSortVector(int argc, char *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
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
    if (hasDuplicates(vec))
    {
        throw std::invalid_argument("Error");
    }
    MergeInsertionSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "After: ";
    printVector(vec);
    printTime(end - start, argc - 1, "std::vector");
}

void PmergeMe::printList(const std::list<int> &lst)
{
    for (const auto &element : lst)
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
    for (auto it = temp.begin(); it != temp.end(); std::advance(it, 2))
    {
        if (*it > *std::next(it))
            pairs.emplace_back(*it, *std::next(it));
        else
            pairs.emplace_back(*std::next(it), *it);
    }
    return pairs;
}

std::list<std::list<int>> PmergeMe::partition(std::list<int> &nums, std::list<int> &groupSizes)
{
    std::list<std::list<int>> partitions;
    auto start = nums.begin();
    for (int size : groupSizes)
    {
        auto end = start;
        std::advance(end, std::min(size, static_cast<int>(std::distance(start, nums.end()))));
        std::list<int> partition(start, end);
        partition.reverse();
        partitions.push_back(partition);
        std::advance(start, size);
    }
    for (const auto &sub_list : partitions)
    {
        printList(sub_list);
        std::cout << "Partition done" << '\n';
    }
    return partitions;
}

std::list<int> PmergeMe::binarySearchLength(const std::list<int> &groupSizes)
{
    std::list<int> result;
    int index = 2;
    for (const auto &size : groupSizes)
    {
        index += size;
        for (int i = 0; i < size; i++)
        {
            result.push_back(index - i - 2);
        }
    }
    return result;
}
/*
This function returns a subsequence of the sorted list that contains the elements up to the upperBound
We know the upperBound index in the original sorted list, but everytime we insert a number into sorted list,
this index will change. So, we get the value of the upperBound and find its position in the new sorted list.
The subsequences are then created from the beginning of the new sorted list to the location of the upperBound value.
*/
std::list<int> PmergeMe::findSubsequence(const std::list<int> &newSequence, const std::list<int> &oldSequence, int upperBoundIndex)
{
    int upperBound = *std::next(oldSequence.begin(), upperBoundIndex);
    auto it = std::find(newSequence.begin(), newSequence.end(), upperBound);
    std::list<int> subsequence(newSequence.begin(), std::next(it, 1));
    // std::cout << "Subsequence with upperBound " << upperBound << ": \n";
    return subsequence;
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

void PmergeMe::binaryInsertionSortList(std::list<int> &subsequenceToInsert, int elemToInsert)
{
    std::cout << "Subsequence to insert: \n";
    printList(subsequenceToInsert);
    int location = binarySearchList(subsequenceToInsert, 0, subsequenceToInsert.size() - 1, elemToInsert);
    std::cout << "Location: " << location << "\n";
    sortedList.insert(std::next(sortedList.begin(), location), elemToInsert);
    std::cout << "\nSorted after inserting:" << elemToInsert << "\n";
    printList(sortedList);
}

void PmergeMe::MergeInsertionSort(std::list<int> &lst)
{
    // Step 1+2: Group the elements into pairs and perform comparisons to determine the larger element in each pair
    if (lst.size() % 2 != 0)
        oddSize = true;
    std::list<std::pair<int, int>> paired = makePairs(lst);
    // Step 3: Sort the larger elements and create a sorted sequence of larger elements in ascending order
    paired.sort();
    for (const auto &pair : paired)
    {
        sortedList.push_back(pair.first);
        unsortedList.push_back(pair.second);
    }
    if (oddSize)
        unsortedList.push_back(lst.back());
    std::cout << "Sorted after step 1 - 3: \n";
    printList(sortedList);
    std::cout << "Unsorted: \n";
    printList(unsortedList);

    // Step 4: Insert the element paired with the smallest element at the start of the sorted sequence
    sortedList.insert(sortedList.begin(), unsortedList.front());
    unsortedList.erase(unsortedList.begin());
    std::cout << "Sorted after step 4: \n";
    printList(sortedList);
    std::cout << "Unsorted: \n";
    printList(unsortedList);

    /*
    Step 5 : Partition the unsorted elems into groups with contiguous indexes.
    The sums of sizes of every two adjacent groups form a sequence of powers of two
    */
    std::list<int> groupSizes = generatePowerSequenceList(unsortedList.size());
    printList(groupSizes);
    std::cout << "Unsorted in partitioned groups: \n";
    std::list<std::list<int>> orderToInsert = partition(unsortedList, groupSizes);

    /*
    Step 6: Insert the remaining elements into the sorted sequence using binary search
    First, find the length of the subsequence to insert the element into
    As we are inserting in order y_4, y_3, y_6, y_5, y_12, y_11, y_10, y_9, y_8, y_7, y_22, y_21...
    The subsequence length is to insert will be up to but not including x_i.
    We then perform a binary search on that subsequence to find the location to insert the element.
    */
    std::list<int> subsequenceLength = binarySearchLength(groupSizes);
    std::cout << "Subsequence length: \n";
    printList(subsequenceLength);
    std::list<int> originalSorted = sortedList;
    for (const auto &uninsertedGroup : orderToInsert)
    {
        for (const auto &element : uninsertedGroup)
        {
            std::list<int> subsequence = findSubsequence(sortedList, originalSorted, subsequenceLength.front());
            binaryInsertionSortList(subsequence, element);
            subsequenceLength.pop_front();
        }
        std::cout << '\n';
    }
    if (std::is_sorted(sortedList.begin(), sortedList.end()))
        std::cout << "Sorted\n";
    else
        std::cout << "Not sorted\n";
    // if (std::is_sorted(sorted.begin(), sorted.end()))
    //     std::cout << "Sorted\n";
    // else
    //     std::cout << "Not sorted\n";
}

bool PmergeMe::hasDuplicates(const std::list<int> &lst)
{
    std::unordered_set<int> set(lst.begin(), lst.end());
    return set.size() != lst.size();
}

void PmergeMe::timeSortList(int argc, char *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
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
    if (hasDuplicates(lst))
    {
        throw std::invalid_argument("Error");
    }
    MergeInsertionSort(lst);
    auto end = std::chrono::high_resolution_clock::now();
    printTime(end - start, argc - 1, "std::list");
}