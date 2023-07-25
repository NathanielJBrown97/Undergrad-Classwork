//
// Created by obses on 5/23/2023.
//
#include "Animal.h"
class Snake : public Animal{
public:
    Snake(float initial_hunger, float initial_thirst) : Animal(initial_hunger, initial_thirst){};
    void Speak() { std::cout << "Sss!" << std::endl; }
};


