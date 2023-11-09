#include "Character.hpp"

Character::Character()
{
    std::cout << CYAN "Character's default constructor called\n" RESET;
}

Character::Character(std::string const &name) : name(name)
{
    std::cout << CYAN "Character's parameter constructor called\n" RESET;
}

Character::Character(const Character &src) : name(src.getName())
{
    std::cout << "Character's copy constructor called\n";
    for (int i = 0; i < maxMaterias; i++)
        inventory[i] = src.inventory[i]->clone();
}

Character &Character::operator=(const Character &src)
{
    std::cout << "Character's copy assignment operator called\n";
    name = src.getName();
    for (int i = 0; i < maxMaterias; i++)
        delete inventory[i];
    for (int i = 0; i < maxMaterias; i++)
        inventory[i] = src.inventory[i]->clone();
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < maxMaterias; i++)
        delete inventory[i];
    std::cout << RED "Character destructor called.\n" RESET;
}

std::string const &Character::getName() const
{
    return name;
}