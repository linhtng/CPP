#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &first_weapon) : name(name), weaponRef(first_weapon)
{
}
HumanA::~HumanA() {}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weaponRef.getType() << '\n';
}
