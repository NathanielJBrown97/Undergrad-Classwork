#include <iostream>

int main()
{
    int age ;
    std::cin >> age ;

    if (age >= 21)
        { std::cout << "Can have a beer" ;}
    else if (age > 17 && age < 22)
        { std::cout << "Can join the military" ; }
    else if (age > 15 && age < 19)
        { std::cout << "Can drive" ; }
    else 
        { std::cout << "Too young" ; }
}