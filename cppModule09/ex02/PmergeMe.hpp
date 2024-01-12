#include <vector>
#include <list>
#include <chrono>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortVector(std::vector<int> &vec);
    void sortList(std::list<int> &lst);

    std::chrono::duration<double> timeSortVector(std::vector<int> &vec);
    std::chrono::duration<double> timeSortList(std::list<int> &lst);
};