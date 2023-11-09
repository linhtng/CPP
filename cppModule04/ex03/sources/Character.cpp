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
        delete inventory[i];
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

void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "Error 404. Material to equip not found!\n";
        return;
    }
    for (int i = 0; i < maxMaterias; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
    std::cout << "No inventory capacity left to equip more Materia.\n";
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= maxMaterias)
    {
        std::cout << "Invalid index. Index must be between 0 and 3.\n";
        return;
    }
    if (!inventory[idx])
    {
        std::cout << "Error 404. Material to unequip not found!\n";
        return;
    }
}
