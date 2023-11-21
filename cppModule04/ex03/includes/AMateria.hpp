#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#define RED "\e[91m"
#define PINK "\e[35m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

#define maxMaterias 4

class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &src);
    AMateria &operator=(const AMateria &src);
    virtual ~AMateria();

    std::string const &getType() const; // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif