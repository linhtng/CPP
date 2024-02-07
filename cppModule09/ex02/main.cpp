#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <int> [<int> ...]\n";
        return 1;
    }
    PmergeMe p;
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << "\n";
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
    // p.sortVectorTest();
    p.sortListTest();
    return 0;
}