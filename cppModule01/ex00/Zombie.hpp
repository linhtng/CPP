#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie(std::string given_name);
    ~Zombie();
    void announce();

private:
    std::string name;
};

#endif