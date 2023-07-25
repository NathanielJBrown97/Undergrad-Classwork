//
// Created by obses on 5/23/2023.
//

#include "Animal.h"
class Hamster : public Animal{
public:
    Hamster(float initial_hunger, float initial_thirst) : Animal(initial_hunger, initial_thirst) {};
    void Speak() { std::cout << "Squeak!" << std::endl;}
};

