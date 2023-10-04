#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " is destroyed." << '\n';
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string given_name)
{
    this->name = given_name;
}