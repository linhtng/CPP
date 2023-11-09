#include "MateriaSource.hpp"

/* Public */

MateriaSource::MateriaSource()
{
    std::cout << CYAN "MateriaSource's default constructor called\n" RESET;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
    std::cout << "MateriaSource's copy constructor called\n";
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    std::cout << "MateriaSource's copy assignment operator called\n";
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < maxMaterias; i++)
        delete learnedMateria[i];
    std::cout << RED "MateriaSource destructor called.\n" RESET;
}

void MateriaSource::learnMateria(AMateria *param)
{
    for (int i = 0; i < maxMaterias; i++)
    {
        if (!learnedMateria[i])
        {
            learnedMateria[i] = param;
            if (i == 3)
                return;
        }
    }
    std::cout << "No capacity left to learn new Materia.\n";
}