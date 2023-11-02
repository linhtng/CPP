#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define RED "\e[31m"
#define RED2 "\e[91m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define RESET "\e[0m"
#define PINK "\e[35m"

#include <iostream>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &rhs);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
};

#endif