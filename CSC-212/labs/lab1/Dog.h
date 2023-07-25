#include "Animal.h"

class Dog : public Animal{
public:
    Dog(float initial_hunger, float initial_thirst) : Animal(initial_hunger, initial_thirst){};
    void Speak() { std::cout << "Woof!" << std::endl; }
};