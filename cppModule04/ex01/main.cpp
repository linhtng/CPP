#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testDeepCopy()
{
    Cat Fluffy;
    Cat raccoon = Fluffy;

    Dog gudBoi;
    Dog veryGudBoi(gudBoi);
}

void moreTestDeepCopy()
{
    Cat catto;

    catto.getBrain()->setIdea(0, "Meow want fish!");
    Cat meowy = catto;

    std::cout << "Catto's 1st thought: " << catto.getBrain()->getIdea(0) << '\n';
    std::cout << "Meowy's 1st thought: " << meowy.getBrain()->getIdea(0) << '\n';

    catto.getBrain()->setIdea(1, "Now meow want treat!");
    std::cout << "Catto's 2nd thought: " << catto.getBrain()->getIdea(1) << '\n';
    std::cout << "Meowy's 2nd thought: " << meowy.getBrain()->getIdea(1) << '\n';
}

int main()
{
    /* std::cout << "Subject test 1\n";
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j; // should not create a leak
    delete i; */

    /* std::cout << "Subject test 2\n";
    int arrLen = 6;
    const Animal *arr[arrLen];
    for (int i = 0; i < arrLen / 2; i++)
        arr[i] = new Dog;
    for (int i = arrLen / 2; i < arrLen; i++)
        arr[i] = new Cat;
    for (int i = 0; i < arrLen; i++)
        delete arr[i]; */

    testDeepCopy();
    moreTestDeepCopy();

    return 0;
}