#include "DiamondTrap.hpp"
#include <stdlib.h> /* srand, rand */
#include <time.h>

int main(void)
{
    std::string trapNameA = "A";
    std::string trapNameB = "B";
    std::string target = "Boss";
    DiamondTrap A(trapNameA);
    DiamondTrap B(trapNameB);

    int damageAmount = 2;
    int repairAmount = 3;

    A.attack(target);
    A.takeDamage(damageAmount);
    A.beRepaired(repairAmount);
    A.guardGate();
    A.whoAmI();

    B.attack(target);
    B.whoAmI();
    B.highFivesGuys();

    return 0;
}