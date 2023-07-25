#include "Cat.h"
#include "Dog.h"
#include "Hamster.h"
#include "Bird.h"
#include "Snake.h"
#include "Animal.h"

#include <iostream>
int main(){

    float hunger_arr[5] = {0, 20, 40, 60, 80};
    float thirst_arr[5] = {10, 30, 50, 70, 90};
    float eat_amount = 25;
    float drink_amount = 50;

    //SET INITIAL HUNGER/thirst VALUES VIA FLOAT ARRAYS inside constructors.
    Cat cat1(hunger_arr[0], thirst_arr[0]);	// object constructed during compile-time
    Dog dog1(hunger_arr[1], thirst_arr[1]);	// object constructed during run-time. 'dog1' is a pointer.
    Snake snake1(hunger_arr[2], thirst_arr[2]); // constructed during runtime. snake1 should be pointer.
    Hamster hamster1(hunger_arr[3], thirst_arr[3]);
    Bird bird1(hunger_arr[4], thirst_arr[4]);


    //INITIAL HUNGER OUTPUTS VIA HUNGER GETTER
    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // The long-form version would be '(*dog1).GetHunger()' and yes, that set of '()' is required.
    std::cout << "Dog hunger: " << dog1.GetHunger() << std::endl;
    std::cout << "Snake hunger: " << snake1.GetHunger() << std::endl;
    std::cout << "Hamster hunger: " << hamster1.GetHunger() << std::endl;
    std::cout << "Bird hunger: " << bird1.GetHunger() << std::endl;

    //INITIATE EAT SUSTENANCE MODIFIER VIA HELPER
    cat1.Eat(10);
    dog1.Eat(20);
    snake1.Eat(30);
    hamster1.Eat(40);
    bird1.Eat(50);

    //OUTPUT MODIFIED HUNGER VALUES VIA GETTER
    std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << dog1.GetHunger() << std::endl;
    std::cout << "Snake hunger: " << snake1.GetHunger() << std::endl;
    std::cout << "Hamster hunger: " << hamster1.GetHunger() << std::endl;
    std::cout << "Bird hunger: " << bird1.GetHunger() << std::endl;

    //CALL SPEAK HELPER FUNCTIONS
    cat1.Speak();
    dog1.Speak();
    snake1.Speak();
    hamster1.Speak();
    bird1.Speak();


    //INITIAL THIRST OUTPUTS VIA THIRST GETTER
    std::cout << "Cat thirst: " << cat1.GetThirst() << std::endl;
    // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // The long-form version would be '(*dog1).GetThirst()' and yes, that set of '()' is required.
    std::cout << "Dog thirst: " << dog1.GetThirst() << std::endl;
    std::cout << "Snake thirst: " << snake1.GetThirst() << std::endl;
    std::cout << "Hamster thirst: " << hamster1.GetThirst() << std::endl;
    std::cout << "Bird thirst: " << bird1.GetThirst() << std::endl;

    //INITIATE DRINK HYDRATION MODIFIER - VIA HELPER
    cat1.Drink(10);
    dog1.Drink(20);
    snake1.Drink(30);
    hamster1.Drink(40);
    bird1.Drink(50);

    //INITIAL THIRST OUTPUTS VIA THIRST GETTER
    std::cout << "Cat thirst: " << cat1.GetThirst() << std::endl;
    // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // The long-form version would be '(*dog1).GetThirst()' and yes, that set of '()' is required.
    std::cout << "Dog thirst: " << dog1.GetThirst() << std::endl;
    std::cout << "Snake thirst: " << snake1.GetThirst() << std::endl;
    std::cout << "Hamster thirst: " << hamster1.GetThirst() << std::endl;
    std::cout << "Bird thirst: " << bird1.GetThirst() << std::endl;

    //Recall speak commands.
    cat1.Speak();
    dog1.Speak();
    snake1.Speak();
    hamster1.Speak();
    bird1.Speak();
}
