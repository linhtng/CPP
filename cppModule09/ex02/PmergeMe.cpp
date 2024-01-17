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

std::vector<int> PmergeMe::generatePowerSequence(int length)
{
    std::vector<int> sequence;
    sequence.reserve(length);

    int power = 2;
    for (int i = 2; i < length; i++)
    {
        sequence.push_back(power);
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
    for (size_t i = 0; i < vec.size() - 1; i += 2)
    {
        pairs.emplace_back(vec[i], vec[i + 1]);
    }
    std::cout << "after pair grouping vector size: " << pairs.size() << "\n";
    for (const auto &pair : pairs)
    {
        std::cout << pair.first << ", " << pair.second << "\n";
    }
    std::cout << "\n";
    return pairs;
}

std::vector<int> PmergeMe::MergeInsertionSort(const std::vector<int> &arr)
{
    // Base case: If the input array has only one element, return it
    if (arr.size() <= 1)
    {
        return arr;
    }
    // Step 1: Group the elements into pairs
    std::vector<std::pair<int, int>> paired = makePairs(arr);
    // Step 2: Perform comparisons to determine the larger element in each pair
    std::vector<int> larger_elements;
    for (const auto &pair : paired)
    {
        larger_elements.push_back(std::max(pair.first, pair.second));
    }
    for (const auto &element : larger_elements)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
    // Step 3: Recursively sort the larger elements
    std::vector<int> sorted_elements = MergeInsertionSort(larger_elements);

    // Step 4: Insert the element paired with the smallest element at the start of the sorted sequence
    int smallest_element = *std::min_element(arr.begin(), arr.end());
    sorted_elements.insert(sorted_elements.begin(), smallest_element);

    // Step 5: Determine the insertion ordering for the remaining elements
    std::vector<int> uninserted_elements;
    for (const auto &element : arr)
    {
        if (std::find(sorted_elements.begin(), sorted_elements.end(), element) == sorted_elements.end())
        {
            uninserted_elements.push_back(element);
        }
    }
    // Step 6: Insert the remaining elements into the sorted sequence using binary search
    std::vector<int> insertion_order = generatePowerSequence(uninserted_elements.size());
    for (const auto &element : insertion_order)
    {
        auto it = std::lower_bound(sorted_elements.begin(), sorted_elements.end(), element);
        sorted_elements.insert(it, element);
    }

    return sorted_elements;
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
    std::vector<int> sorted = MergeInsertionSort(vec);
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