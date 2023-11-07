#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << CYAN << j->getType() << " says: ";
    j->makeSound(); // will output the cat sound!
    std::cout << CYAN << i->getType() << " says: ";
    i->makeSound(); // will output the dog sound
    std::cout << CYAN "Animal says: ";
    meta->makeSound(); // ???

    delete j;
    delete i;
    delete meta;

    std::cout << "\n/* Test with wrong class that don't use virtual keyword: */\n";
    const WrongAnimal *metaWrong = new WrongAnimal();
    const WrongAnimal *wrongi = new WrongCat();
    const WrongCat *wrongj = new WrongCat();

    std::cout << PINK << "WrongAnimal says: ";
    metaWrong->makeSound(); // ????
    std::cout << PINK << wrongi->getType() << " says: ";
    wrongi->makeSound(); // will output the ????
    std::cout << PINK << wrongj->getType() << " says: ";
    wrongj->makeSound(); // will output the ????

    delete wrongi;
    delete wrongj;
    delete metaWrong;

    return 0;
}