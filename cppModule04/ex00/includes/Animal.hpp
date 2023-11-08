#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define CYAN "\033[36m"
#define RESET "\e[0m"

class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &rhs);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string type;
};

#endif