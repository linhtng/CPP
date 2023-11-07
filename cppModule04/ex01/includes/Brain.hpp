#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
    Brain();
    Brain(std::string type);
    Brain(const Brain &other);
    Brain &operator=(const Brain &rhs);
    virtual ~Brain();

private:
    std::string ideas[100];
};

#endif