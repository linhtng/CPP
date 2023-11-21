#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void subjectTest()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void materiaSourceTest()
{
    IMateriaSource *src = new MateriaSource();
    for (int i = 0; i < 5; i++)
        src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    delete src;
}

int main()
{
    subjectTest();
    materiaSourceTest();

    return 0;
}
