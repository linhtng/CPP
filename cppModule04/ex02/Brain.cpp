#include "Brain.hpp"

/* Public */

Brain::Brain()
{
    std::cout << CYAN "Brain's default constructor called\n" RESET;
}

Brain::Brain(const Brain &rhs)
{
    std::cout << CYAN "Brain's copy constructor called\n" RESET;
    for (int i = 0; i < 100; i++)
        ideas[i] = rhs.ideas[i];
}

Brain &Brain::operator=(const Brain &rhs)
{
    std::cout << CYAN "Brain's copy assignment operator called\n" RESET;
    for (int i = 0; i < 100; i++)
        ideas[i] = rhs.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << RED "Brain destructor called.\n" RESET;
}

void Brain::setIdea(int ideaID, std::string idea)
{
    ideas[ideaID] = idea;
}

std::string Brain::getIdea(int ideaID) const
{
    return ideas[ideaID];
}
