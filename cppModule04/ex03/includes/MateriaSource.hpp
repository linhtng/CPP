#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *learnedMateria[maxMaterias];

public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    MateriaSource &operator=(const MateriaSource &src);
    ~MateriaSource();
    void learnMateria(AMateria *param);
    AMateria *createMateria(std::string const &type);
};

#endif