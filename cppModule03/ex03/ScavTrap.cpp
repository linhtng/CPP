#include "ScavTrap.hpp"

/* Public */

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap's default constructor called.\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " is constructed.\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &rhs)
{
    std::cout << "ScavTrap's copy constructor called\n";
    name = rhs.name;
    hitPoints = rhs.hitPoints;
    energyPoints = rhs.energyPoints;
    attackDamage = rhs.attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    std::cout << "ScavTrap's copy assignment operator called\n";
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

void ScavTrap::guardGate()
{
    std::cout << CYAN "ScavTrap " << name << " is now in Gate keeper mode.\n" RESET;
}

/* Private */
