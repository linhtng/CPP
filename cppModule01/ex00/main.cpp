#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *heap = newZombie("Heap");
    heap->announce();
    delete heap;
    randomChump("Stack");
    return 0;
}