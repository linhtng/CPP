#include "ClapTrap.hpp"
#include <stdlib.h> /* srand, rand */
#include <time.h>

int main(void)
{
    std::string trapNameA = "A";
    std::string trapNameB = "B";
    std::string target = "Boss";
    ClapTrap A(trapNameA);
    ClapTrap B(trapNameB);

    int damageAmount = 2;
    int repairAmount = 3;
    A.attack(target);
    A.takeDamage(damageAmount);
    A.beRepaired(repairAmount);

    for (int i = 0; i < 12; i++)
        B.attack(target);
    B.takeDamage(damageAmount);
    B.beRepaired(repairAmount);

    ClapTrap C(A);
    srand(time(NULL));

    int randomDamageAmount = rand() % 20 + 1;
    std::cout << "randomDamageAmount: " << randomDamageAmount << '\n';
    int randomRepairAmount = rand() % 10 + 1;
    std::cout << "randomRepairAmount: " << randomRepairAmount << '\n';

    C.attack(target);
    C.takeDamage(randomDamageAmount);
    C.beRepaired(randomRepairAmount);

    ClapTrap D;
    D = C;

    D.attack(target);
    D.takeDamage(randomDamageAmount);
    D.beRepaired(randomRepairAmount);

    return 0;
}