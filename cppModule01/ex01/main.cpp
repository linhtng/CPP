#include "Zombie.hpp"
#include <cstdlib>

Zombie *zombieHorde(int N, std::string name);

int main(int arc, char **arv)
{
    if (arc != 3)
    {
        std::cout << "Give name and size to your formidable zombie army.\n";
        return 0;
    }
    int intValue = atoi(arv[2]);
    Zombie *testHorde = zombieHorde(intValue, arv[1]);
    if (testHorde)
    {
        for (int i = 0; i < intValue; ++i)
            testHorde[i].announce();
        delete[] testHorde;
    }
    return 0;
}