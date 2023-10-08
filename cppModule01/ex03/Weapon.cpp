#include "Weapon.hpp"

Weapon::Weapon(std::string begin_type) : type(begin_type) {}
Weapon::~Weapon() {}

std::string const &Weapon::getType() const
{
    return type;
}

void Weapon::setType(std::string param_type)
{
    this->type = param_type;
}