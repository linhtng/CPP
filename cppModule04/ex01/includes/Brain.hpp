#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &rhs);
    virtual ~Brain();

    void getIdea(int ideaID) const;
    std::string setIdea(int ideaID, std::string idea);

private:
    std::string ideas[100];
};

#endif