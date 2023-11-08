#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#define RED "\e[91m"
#define PINK "\e[35m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

class Brain
{
public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &rhs);
    ~Brain();

    std::string getIdea(int ideaID) const;
    void setIdea(int ideaID, std::string idea);

private:
    std::string ideas[100];
};

#endif