#include "FragTrap.hpp"
#include <stdlib.h> /* srand, rand */
#include <time.h>

int main(void)
{
    std::string trapNameA = "A";
    std::string trapNameB = "B";
    std::string target = "Boss";
    FragTrap A(trapNameA);
    FragTrap B(trapNameB);

    int damageAmount = 2;
    int repairAmount = 3;
    A.attack(target);
    A.takeDamage(damageAmount);
    A.beRepaired(repairAmount);

    B.attack(target);
    B.highFivesGuys();

    FragTrap C(A);
    srand(time(NULL));

    int randomDamageAmount = rand() % 200 + 1;
    std::cout << "randomDamageAmount: " << randomDamageAmount << '\n';
    int randomRepairAmount = rand() % 50 + 1;
    std::cout << "randomRepairAmount: " << randomRepairAmount << '\n';

    C.attack(target);
    C.takeDamage(randomDamageAmount);
    C.beRepaired(randomRepairAmount);
    C.highFivesGuys();

    FragTrap D;
    D = C;

    D.attack(target);
    D.takeDamage(randomDamageAmount);
    D.beRepaired(randomRepairAmount);

    return 0;
}