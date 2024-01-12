#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i)
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

    PmergeMe p;
    auto vecTime = p.timeSortVector(vec);
    auto lstTime = p.timeSortList(lst);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime.count() << " us\n";
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " << lstTime.count() << " us\n";

    return 0;
}