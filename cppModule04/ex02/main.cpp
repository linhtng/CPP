#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;

    // Animal animal; //error: variable type 'Animal' is an abstract class

    return 0;
}