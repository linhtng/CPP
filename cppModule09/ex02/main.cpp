#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <int> [<int> ...]\n";
        return 1;
    }
    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i)
    {
        try
        {
            int num = std::stoi(argv[i]);
            if (num < 0)
            {
                std::cout << "Error\n";
                return 1;
            }
            vec.push_back(num);
            lst.push_back(num);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    std::cout << "Before: ";
    for (auto &i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    PmergeMe p;
    auto vecTime = p.timeSortVector(vec);
    // auto lstTime = p.timeSortList(lst);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << vecTime.count() << " us\n";
    // std::cout << "Time to process a range of " << lst.size()
    //           << " elements with std::list: " << lstTime.count() << " us\n";

    return 0;
}