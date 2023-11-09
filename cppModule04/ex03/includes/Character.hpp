#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class Character
{
private:
    AMateria *inventory[maxMaterias] = {};
    AMateria *unequipInventory[maxMaterias] = {};
    std::string name;

public:
    Character();
    Character(std::string const &name);
    Character(const Character &src);
    Character &operator=(const Character &src);
    ~Character() {}

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif