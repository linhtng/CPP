#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *heap = newZombie("Heap");
    if (!heap)
    {
        std::cout << "Fail to get newZombie heap\n";
        return 1;
    }
    heap->announce();
    delete heap;
    randomChump("Stack");
    return 0;
}