#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}
HumanB::~HumanB() {}

void HumanB::attack() const
{
    if (weaponPtr)
        std::cout << name << " attacks with their " << weaponPtr->getType() << '\n';
    else
        std::cout << name << " attacks with their bare hands. \n";
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weaponPtr = &newWeapon;
}
