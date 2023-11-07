#include "Brain.hpp"

/* Public */

Brain::Brain()
{
    std::cout << "Brain's default constructor called\n";
}

Brain::Brain(const Brain &rhs)
{
    std::cout << "Brain's copy constructor called\n";
}

Brain &Brain::operator=(const Brain &rhs)
{
    std::cout << "Brain's copy assignment operator called\n";
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called.\n";
}
