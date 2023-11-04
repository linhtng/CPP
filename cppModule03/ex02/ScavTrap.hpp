#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#define CYAN "\033[36m"

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &rhs);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};

#endif