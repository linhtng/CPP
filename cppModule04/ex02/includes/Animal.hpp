#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RED "\e[91m"
#define PINK "\e[35m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

/*
Without virtual keyword over Animal destructor, there will be compiling error
"delete called on non-final 'Animal' that has virtual functions but non-virtual destructor"
If you remove -Werror flag, it will compile but then there is memory leaks, because then
the derived classes' destructor, where we call delete Brain, are never called.
*/

class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &rhs);
    virtual ~Animal();

    virtual void makeSound() const = 0;
    std::string getType() const;

protected:
    std::string type;
};

#endif