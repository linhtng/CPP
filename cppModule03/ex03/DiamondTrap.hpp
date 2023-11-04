#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#define CYAN "\033[36m"

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &rhs);
    ~DiamondTrap();

    void attack(const std::string &target);
    void whoAmI();
    void my_stats();

private:
    std::string name;
};

#endif