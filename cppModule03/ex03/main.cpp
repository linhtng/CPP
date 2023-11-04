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

    A.my_stats();
    A.attack(target);
    A.takeDamage(damageAmount);
    A.beRepaired(repairAmount);
    A.my_stats();

    B.my_stats();
    B.attack(target);
    B.whoAmI();
    B.my_stats();

    DiamondTrap C(A);
    srand(time(NULL));

    int randomDamageAmount = rand() % 200 + 1;
    std::cout << "randomDamageAmount: " << randomDamageAmount << '\n';
    int randomRepairAmount = rand() % 50 + 1;
    std::cout << "randomRepairAmount: " << randomRepairAmount << '\n';

    C.attack(target);
    C.takeDamage(randomDamageAmount);
    C.beRepaired(randomRepairAmount);
    C.whoAmI();
    C.my_stats();

    DiamondTrap D;
    D = C;

    D.attack(target);
    D.takeDamage(randomDamageAmount);
    D.beRepaired(randomRepairAmount);
    D.my_stats();

    return 0;
}