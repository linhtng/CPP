#include "ScavTrap.hpp"

/* Public */

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap's default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name) : name(name),
                                       hitPoints(10),
                                       energyPoints(10),
                                       attackDamage(0)
{
    std::cout << "ScavTrap " << name << " is constructed.\n";
}

ScavTrap::ScavTrap(const ScavTrap &rhs)
{
    std::cout << "Copy constructor called\n";
    *this = rhs;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    std::cout << "Copy assignment operator called\n";
    name = rhs.name;
    hitPoints = rhs.hitPoints;
    energyPoints = rhs.energyPoints;
    attackDamage = rhs.attackDamage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " is destructed.\n";
}

void ScavTrap::attack(const std::string &target)
{
    if (hitPoints <= 0)
    {
        std::cout << YELLOW "ScavTrap "
                  << name << " was defeated. It can't attack.\n" RESET;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << YELLOW "ScavTrap " << name << " can't attack. ";
        std::cout << "Energy level critical!\n" RESET;
        return;
    }
    std::cout << PINK "ScavTrap " << name << " attacks "
              << target << ", causing " << attackDamage
              << " points of damage!\n" RESET;
    energyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << YELLOW "ScavTrap " << name
                  << " was defeated. Leave it alone!\n" RESET;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << YELLOW "ScavTrap " << name
                  << "'s battery is burnt out. Leave it alone!\n" RESET;
        return;
    }
    hitPoints -= amount;
    if (hitPoints > 0)
        std::cout << RED "ScavTrap " << name << " take "
                  << amount << " point of damage. "
                  << "Its HP is now " << hitPoints << RESET << '\n';
    else
        std::cout << RED2 "ScavTrap " << name << " take "
                  << amount << " point of damage. "
                  << "It is defeated!" << RESET << '\n';
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << YELLOW "ScavTrap " << name
                  << " was defeated beyond healing!\n" RESET;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << YELLOW "ScavTrap " << name << " can't heal itself. ";
        std::cout << "Energy level critical!\n" RESET;
        return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << GREEN "ScavTrap " << name << " repair itself "
              << amount << " hit points back. "
              << "Its HP is now " << hitPoints << RESET << '\n';
}

/* Private */
