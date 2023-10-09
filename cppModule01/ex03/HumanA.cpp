#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &firstWeapon) : name(name), weaponRef(firstWeapon)
{
}
HumanA::~HumanA() {}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weaponRef.getType() << '\n';
}
