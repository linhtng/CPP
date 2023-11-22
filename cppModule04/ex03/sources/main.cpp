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
    AMateria *tmp;

    tmp = src->createMateria("ice");
    for (int i = 0; i < 5; i++)
        src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    delete src;
}

void materiaTest()
{
    Ice *ice = new Ice();
    Cure *cure = new Cure();
    // AMateria *empty = NULL;

    AMateria *iceCloneTest = ice->clone();
    AMateria *cureCloneTest = cure->clone();

    ICharacter *me = new Character("me");
    // me->equip(empty);
    me->equip(iceCloneTest);
    me->equip(cureCloneTest);
    me->equip(ice);
    me->equip(cure);

    Ice moreIce(*ice);
    me->equip(&moreIce);

    // ICharacter *bob = NULL;
    // me->use(0, *bob);
    for (int i = 0; i < 4; i++)
        me->use(i, *me);

    delete me;
}

void characterEquipTest()
{
    Character *me = new Character("me");
    // AMateria *empty = NULL;
    // mew->equip(empty);

    Ice *ice = new Ice();
    me->equip(ice);
    Character mew = *me;

    mew.use(0, mew);

    Cure *cure = new Cure();
    me->equip(cure);

    me->use(1, *me);
    mew.use(1, mew);

    // delete ice;
    delete me;

    // Cure *cureUnequipTest = new Cure();
    // mew.equip(cureUnequipTest);
    // mew.unequip(0);
    // mew.unequip(1);
    // mew.unequip(5);

    // if (mew.unequipCheck())
    //     delete cureUnequipTest;
}

void characterUnequipTest()
{
    Character *mew2 = new Character("mew2");
    Cure *cureUnequipTest = new Cure();
    mew2->equip(cureUnequipTest);

    mew2->unequip(0);
    mew2->unequip(1);
    mew2->unequip(5);

    if (mew2->unequipCheck())
        delete cureUnequipTest;
    delete mew2;
}

int main()
{
    subjectTest();
    // materiaSourceTest();
    //  materiaTest();

    // characterEquipTest();
    // characterUnequipTest();

    return 0;
}
