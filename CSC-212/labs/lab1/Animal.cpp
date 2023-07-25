#include "Animal.h"

Animal::Animal(float initial_hunger, float initial_thirst){
    this->hunger = initial_hunger;
    this->thirst = initial_thirst;
}

float Animal::GetHunger(){

    return this->hunger;
}
void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}
//definition of thirst getter - returns current float for thirst
float Animal::GetThirst(){
    return this->thirst;
}
//definition for thirst helper Drink() function passed hydration value - returns thirst val + hydration
void Animal::Drink(float hydration){
    this->thirst += hydration;
}