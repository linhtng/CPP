#include "DiamondTrap.hpp"

/* Public */

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap's default constructor called.\n";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTrap " << name << " is constructed.\n";
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap's copy constructor called\n";
    name = rhs.name;
    ClapTrap::name = name + "_clap_name";
    hitPoints = rhs.hitPoints;
    energyPoints = rhs.energyPoints;
    attackDamage = rhs.attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap's copy assignment operator called\n";
    name = rhs.name;
    hitPoints = rhs.hitPoints;
    energyPoints = rhs.energyPoints;
    attackDamage = rhs.attackDamage;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " is destructed.\n";
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << CYAN "DiamondTrap "
              << ": Hi there! 🖐️ I'm " << name << " and my ClapTrap name's "
              << ClapTrap::name << RESET << '\n';
}

void DiamondTrap::my_stats()
{
    std::cout << CYAN "My HP: " << hitPoints
              << " My EP: " << energyPoints
              << " My Damage: " << attackDamage << RESET << '\n';
}

/* Private */
