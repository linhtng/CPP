#include "FragTrap.hpp"

/* Public */

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap's default constructor called.\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    this->my_stats();
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " is constructed.\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    this->my_stats();
}

FragTrap::FragTrap(const FragTrap &rhs)
{
    std::cout << "FragTrap's copy constructor called\n";
    name = rhs.name;
    hitPoints = rhs.hitPoints;
    energyPoints = rhs.energyPoints;
    attackDamage = rhs.attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << "FragTrap's copy assignment operator called\n";
    name = rhs.name;
    hitPoints = rhs.hitPoints;
    energyPoints = rhs.energyPoints;
    attackDamage = rhs.attackDamage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " is destructed.\n";
}

void FragTrap::attack(const std::string &target)
{
    if (hitPoints <= 0)
    {
        std::cout << YELLOW "FragTrap "
                  << name << " was defeated. It can't attack.\n" RESET;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << YELLOW "FragTrap " << name << " can't attack. ";
        std::cout << "Energy level critical!\n" RESET;
        return;
    }
    std::cout << PINK "FragTrap " << name << " attacks "
              << target << ", causing " << attackDamage
              << " points of damage!\n" RESET;
    energyPoints--;
}

void FragTrap::highFivesGuys()
{
    std::cout << CYAN "FragTrap " << name << ": Hi there! 🖐️ Can I get a positive high five from my awesome bestie? 🌟🙌\n" RESET;
}

int FragTrap::getDamage()
{
    std::cout << "FragTrap damage is: " << attackDamage << '\n';
    return attackDamage;
}

void FragTrap::my_stats()
{
    std::cout << CYAN "FragTrap stats. My HP: " << hitPoints
              << " My EP: " << energyPoints
              << " My Damage: " << attackDamage << RESET << '\n';
}

/* Private */
