#include <iostream>

// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    // virtual
    void makeSound()
    {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        std::cout << "Dog barks" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound()
    {
        std::cout << "Cat meows" << std::endl;
    }
};

int main()
{
    Animal *animalPtr;
    Dog dogObj;
    Cat catObj;

    animalPtr = &dogObj;
    animalPtr->makeSound(); // Output: "Dog barks"

    // animalPtr = &catObj;
    // animalPtr->makeSound(); // Output: "Cat meows"

    return 0;
}
