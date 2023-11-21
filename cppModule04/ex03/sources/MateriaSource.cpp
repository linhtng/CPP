#include "MateriaSource.hpp"

/* Public */

MateriaSource::MateriaSource()
{
    // std::cout << CYAN "MateriaSource's default constructor called\n" RESET;
    for (int i = 0; i < maxMaterias; i++)
        learnedMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
    // std::cout << "MateriaSource's copy constructor called\n";
    for (int i = 0; i < maxMaterias; i++)
    {
        delete learnedMateria[i];
        learnedMateria[i] = createMateria(rhs.learnedMateria[i]->getType());
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    // std::cout << "MateriaSource's copy assignment operator called\n";
    for (int i = 0; i < maxMaterias; i++)
    {
        delete learnedMateria[i];
        learnedMateria[i] = createMateria(rhs.learnedMateria[i]->getType());
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < maxMaterias; i++)
        delete learnedMateria[i];
    // std::cout << RED "MateriaSource destructor called.\n" RESET;
}

void MateriaSource::learnMateria(AMateria *param)
{
    for (int i = 0; i < maxMaterias; i++)
    {
        if (!learnedMateria[i])
        {
            learnedMateria[i] = param;
            return;
        }
    }
    std::cout << "No capacity left to learn new Materia.\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < maxMaterias; i++)
    {
        if (learnedMateria[i] && learnedMateria[i]->getType() == type)
            return learnedMateria[i]->clone();
    }
    return 0;
}