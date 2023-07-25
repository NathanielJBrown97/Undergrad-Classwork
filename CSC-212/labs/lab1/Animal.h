#ifndef LAB_01_CODE_ANIMAL_H
#define LAB_01_CODE_ANIMAL_H

#include <iostream>

class Animal{
private:
    float hunger;
    //adding thirst
    float thirst;
public:
    Animal(float initial_hunger, float initial_thirst);
    void Eat(float sustenance);
    float GetHunger();
    //add Thirst modifier, followed by thirst getter.
    void Drink(float hydration);
    float GetThirst();
    virtual void Speak() = 0;
};

#endif //LAB_01_CODE_ANIMAL_H
