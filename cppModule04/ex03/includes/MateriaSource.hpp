#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *learnedMateria[maxMaterias] = {};

public:
    ~MateriaSource();
    virtual void learnMateria(AMateria *param);
    virtual AMateria *createMateria(std::string const &type);
};

#endif