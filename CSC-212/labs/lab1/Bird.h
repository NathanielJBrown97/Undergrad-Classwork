//
// Created by obses on 5/23/2023.
//

#include "Animal.h"
class Bird : public Animal{
public:
    Bird(float initial_hunger, float initial_thirst) : Animal(initial_hunger, initial_thirst){};
    void Speak(){ std::cout << "Chirp" << std::endl; }

};

