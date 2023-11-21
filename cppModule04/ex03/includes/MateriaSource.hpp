#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *learnedMateria[maxMaterias];

public:
    ~MateriaSource();
    void learnMateria(AMateria *param);
    AMateria *createMateria(std::string const &type);
};

#endif