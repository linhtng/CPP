#include "ClapTrap.hpp"

/* Public */

ClapTrap::ClapTrap() : hitPoints(10),
                       energyPoints(10),
                       attackDamage(0)
{
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name),
                                       hitPoints(10),
                                       energyPoints(10),
                                       attackDamage(0)
{
    std::cout << "ClapTrap " << name << " is constructed.\n";
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    std::cout << "Copy constructor called\n";
    name = rhs.name;
    hitPoints = rhs.hitPoints;
    energyPoints = rhs.energyPoints;
    attackDamage = rhs.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "Copy assignment operator called\n";
    name = rhs.name;
    hitPoints = rhs.hitPoints;
    energyPoints = rhs.energyPoints;
    attackDamage = rhs.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " is destructed.\n";
}

void ClapTrap::attack(const std::string &target)
{
    if (hitPoints <= 0)
    {
        std::cout << YELLOW "ClapTrap "
                  << name << " was defeated. It can't attack.\n" RESET;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << YELLOW "ClapTrap " << name << " can't attack. ";
        std::cout << "Energy level critical!\n" RESET;
        return;
    }
    std::cout << PINK "ClapTrap " << name << " attacks "
              << target << ", causing " << attackDamage
              << " points of damage!\n" RESET;
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << YELLOW "ClapTrap " << name
                  << " was defeated. Leave it alone!\n" RESET;
        return;
    }
    hitPoints -= amount;
    if (hitPoints > 0)
        std::cout << RED "ClapTrap " << name << " take "
                  << amount << " point of damage. "
                  << "Its HP is now " << hitPoints << RESET << '\n';
    else
        std::cout << RED2 "ClapTrap " << name << " take "
                  << amount << " point of damage. "
                  << "It is defeated!" << RESET << '\n';
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << YELLOW "ClapTrap " << name
                  << " was defeated beyond healing!\n" RESET;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << YELLOW "ClapTrap " << name << " can't heal itself. ";
        std::cout << "Energy level critical!\n" RESET;
        return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << GREEN "ClapTrap " << name << " repair itself "
              << amount << " hit points back. "
              << "Its HP is now " << hitPoints << RESET << '\n';
}

/* Private */
