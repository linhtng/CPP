#include "ScavTrap.hpp"
#include <stdlib.h> /* srand, rand */
#include <time.h>

int main(void)
{
    std::string trapNameA = "A";
    std::string trapNameB = "B";
    std::string target = "Boss";
    ScavTrap A(trapNameA);
    ScavTrap B(trapNameB);

    int damageAmount = 2;
    int repairAmount = 3;
    A.attack(target);
    A.takeDamage(damageAmount);
    A.beRepaired(repairAmount);

    B.attack(target);
    B.guardGate();

    ScavTrap C(A);
    srand(time(NULL));

    int randomDamageAmount = rand() % 20 + 1;
    std::cout << "randomDamageAmount: " << randomDamageAmount << '\n';
    int randomRepairAmount = rand() % 50 + 1;
    std::cout << "randomRepairAmount: " << randomRepairAmount << '\n';

    C.attack(target);
    C.takeDamage(randomDamageAmount);
    C.beRepaired(randomRepairAmount);
    C.guardGate();

    ScavTrap D;
    D = C;

    D.attack(target);
    D.takeDamage(randomDamageAmount);
    D.beRepaired(randomRepairAmount);

    return 0;
}