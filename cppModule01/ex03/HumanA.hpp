#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon &firstWeapon);
    ~HumanA();
    void attack() const;

private:
    std::string name;
    Weapon &weaponRef;
};

#endif