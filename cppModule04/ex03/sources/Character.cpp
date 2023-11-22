#include "Character.hpp"

Character::Character()
{
    // std::cout << CYAN "Character's default constructor called\n" RESET;
    for (int i = 0; i < maxMaterias; i++)
        inventory[i] = NULL;
    unequipDone = false;
}

Character::Character(std::string const &name) : name(name)
{
    // std::cout << CYAN "Character's parameter constructor called\n" RESET;
    for (int i = 0; i < maxMaterias; i++)
        inventory[i] = NULL;
    unequipDone = false;
}

Character::Character(const Character &src)
{
    // std::cout << "Character's copy constructor called\n";
    for (int i = 0; i < maxMaterias; i++)
        inventory[i] = NULL;
    *this = src;
}

Character &Character::operator=(const Character &src)
{
    // std::cout << "Character's copy assignment operator called\n";
    name = src.getName();
    for (int i = 0; i < maxMaterias; i++)
    {
        if (inventory[i])
            delete inventory[i];
        if (src.inventory[i])
            inventory[i] = src.inventory[i]->clone();
    }
    unequipDone = false;
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < maxMaterias; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    // std::cout << RED "Character destructor called.\n" RESET;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "Error 404. Materia to equip not found!\n";
        return;
    }
    for (int i = 0; i < maxMaterias; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            // std::cout << "Materia " << m->getType() << " is equipped in slot " << i << '\n';
            return;
        }
    }
    std::cout << "No inventory capacity left to equip more Materia.\n";
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= maxMaterias)
    {
        std::cout << "Invalid index. Index must be between 0 and ";
        std::cout << maxMaterias << '\n';
        return;
    }
    if (!inventory[idx])
    {
        std::cout << "Error 404. Material to unequip not found at slot " << idx << '\n';
        return;
    }
    std::string userInput;
    userInput = unequipVerify(idx);
    if (userInput.empty() || userInput != "Y")
    {
        std::cout << RED "Unequip operation aborted. Save the addresses before calling unequip()!\n" RESET;
        return;
    }
    std::cout << "Materia " << inventory[idx]->getType() << " is unequipped in slot " << idx << '\n';
    inventory[idx] = NULL;
    unequipDone = true;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= maxMaterias)
    {
        std::cout << "Invalid index. Index must be between 0 and ";
        std::cout << maxMaterias << '\n';
        return;
    }
    if (!inventory[idx])
    {
        std::cout << "Error 404. Material to use not found at slot " << idx << '\n';
        return;
    }
    ICharacter *nullCheck = &target;
    if (nullCheck)
        inventory[idx]->use(target);
    else
        std::cout << "Error 404. Target not found in use()!\n";
}

std::string Character::unequipVerify(int idx)
{
    std::cout << RED "Did you save the address of character " << this->getName() << "'s Materia number "
              << idx << " before calling unequip(): [Y/n]\n" RESET;
    std::string input;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return ("");
    return input;
}

bool Character::unequipCheck()
{
    return unequipDone;
}
