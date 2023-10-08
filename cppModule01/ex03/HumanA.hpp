#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon &first_weapon);
    ~HumanA();
    void attack() const;

private:
    std::string name;
    Weapon &weaponRef;
};

#endif