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
    for (int i = 2; i < length; i++)
    {
        sequence.push_back(power);
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

std::list<int> PmergeMe::MergeInsertionSort(const std::list<int> &arr)
{
    // Base case: If the input array has only one element, return it
    if (arr.size() <= 1)
    {
        return arr;
    }
    // Step 1: Group the elements into pairs
    std::list<std::pair<int, int>> pairs;
    auto it = arr.begin();
    while (it != arr.end())
    {
        if (std::next(it) != arr.end())
        {
            pairs.emplace_back(*it, *std::next(it));
            std::advance(it, 2);
        }
        else
        {
            pairs.emplace_back(*it, *it);
            break;
        }
    }

    // Step 2: Perform comparisons to determine the larger element in each pair
    std::list<int> larger_elements;
    for (const auto &pair : pairs)
    {
        larger_elements.push_back(std::max(pair.first, pair.second));
    }

    // Step 3: Recursively sort the larger elements
    std::list<int> sorted_elements = MergeInsertionSort(larger_elements);

    // Step 4: Insert the element paired with the smallest element at the start of the sorted sequence
    int smallest_element = *std::min_element(arr.begin(), arr.end());
    sorted_elements.push_front(smallest_element);

    // Step 5: Determine the insertion ordering for the remaining elements
    std::list<int> uninserted_elements;
    for (const auto &element : arr)
    {
        if (std::find(sorted_elements.begin(), sorted_elements.end(), element) == sorted_elements.end())
        {
            uninserted_elements.push_back(element);
        }
    }
    std::list<int> insertion_order = generatePowerSequenceList(uninserted_elements.size());

    // Step 6: Insert the remaining elements into the sorted sequence using binary search
    for (const auto &element : insertion_order)
    {
        auto it = std::lower_bound(sorted_elements.begin(), sorted_elements.end(), element);
        sorted_elements.insert(it, element);
    }

    return sorted_elements;
}

std::chrono::duration<double> PmergeMe::timeSortVector(std::vector<int> &vec)
{
    auto start = std::chrono::high_resolution_clock::now();
    MergeInsertionSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    // std::cout << "sorted size: " << sorted.size() << "\n";
    // std::cout << "After sort for vector: ";
    // for (const auto &element : sorted)
    // {
    //     std::cout << element << " ";
    // }
    // std::cout << "\n";
    return end - start;
}

std::chrono::duration<double> PmergeMe::timeSortList(std::list<int> &lst)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::list<int> sorted = MergeInsertionSort(lst);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "After sort for list: ";
    for (const auto &element : sorted)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
    return end - start;
}