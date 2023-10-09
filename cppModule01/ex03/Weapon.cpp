#include "Weapon.hpp"

Weapon::Weapon(std::string firstType) : type(firstType) {}
Weapon::~Weapon() {}

std::string const &Weapon::getType() const
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}