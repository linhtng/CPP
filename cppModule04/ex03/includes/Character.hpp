#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <stddef.h>

class Character : public ICharacter
{
private:
    AMateria *inventory[maxMaterias];
    std::string name;
    bool unequipDone;

public:
    Character();
    Character(std::string const &name);
    Character(const Character &src);
    Character &operator=(const Character &src);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    std::string unequipVerify(int idx);
    bool unequipCheck();
};

#endif