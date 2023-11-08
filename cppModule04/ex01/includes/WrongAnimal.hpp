#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#define PINK "\e[35m"
#define RESET "\e[0m"

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &rhs);
    virtual ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;

protected:
    std::string type;
};

#endif