#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define CYAN "\033[36m"

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &rhs);
    ~FragTrap();

    void attack(const std::string &target);
    void highFivesGuys();
};

#endif