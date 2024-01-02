#include "MutantStack.hpp"
#include <list>

void subjectTest()
{
    std::cout << CYAN "Subject test using MutantStack:" RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top elem: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Stack size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Iterate through the stack and print out its content: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << CYAN "Subject test using std::list, output should be the same" RESET << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << "Top elem: " << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << "List size: " << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    std::cout << "Iterate through the list and print out its content: " << std::endl;
    for (std::list<int>::iterator itList = mlist.begin(); itList != mlist.end(); ++itList)
        std::cout << *itList << std::endl;
    std::stack<int, std::list<int> > sList(mlist);
}

void subjectTestReverseIte()
{
    std::cout << CYAN "Test using MutantStack reverse ite:" RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::reverse_iterator it = mstack.rBegin();
    MutantStack<int>::reverse_iterator ite = mstack.rEnd();
    std::cout << "Reverse iterate through the stack and print out its content: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    MutantStack<int> mstack2(mstack); //test copy constructor
    std::cout << "Is new stack empty? " << (mstack2.empty() ? "Yes" : "No") << std::endl;
    MutantStack<int>::iterator it2 = mstack2.begin();
    MutantStack<int>::iterator ite2 = mstack2.end();
    std::cout << "Iterate through the stack 2 and print out its content: " << std::endl;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    MutantStack<int> mstack3;
    std::cout << "Is new stack empty before assignment operator called? " << (mstack3.empty() ? "Yes" : "No") << std::endl;
    mstack3 = mstack;
    std::cout << "Is new stack empty after assignment operator called? " << (mstack2.empty() ? "Yes" : "No") << std::endl;
}

int main()
{
    // subjectTest();
    subjectTestReverseIte();

    return 0;
}