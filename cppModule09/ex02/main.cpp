#include "PmergeMe.hpp"

bool hasDuplicates(const std::list<int> &lst)
{
    std::unordered_set<int> set(lst.begin(), lst.end());
    return set.size() != lst.size();
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <int> [<int> ...]\n";
        return 1;
    }
    PmergeMe p;
    // std::cout << "Before: ";
    // for (int i = 1; i < argc; i++)
    // {
    //     std::cout << argv[i] << " ";
    // }
    // std::cout << "\n";
    try
    {
        // p.timeSortVector(argc, argv);
        p.timeSortList(argc, argv);
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Error: invalid input\n";
        return 1;
    }
    // auto lstTime = p.timeSortList(lst);

    // std::cout << "Time to process a range of " << vec.size()
    //           << " elements with std::vector: " << vecTime.count() << " us\n";
    // std::cout << "Time to process a range of " << lst.size()
    //           << " elements with std::list: " << lstTime.count() << " us\n";

    return 0;
}