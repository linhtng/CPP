#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
public:
    Weapon(std::string begin_type);
    ~Weapon();
    std::string const &getType() const;
    void setType(std::string param_type);

private:
    std::string type;
};

#endif