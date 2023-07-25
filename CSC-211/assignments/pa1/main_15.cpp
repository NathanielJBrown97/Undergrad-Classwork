#include <iostream>

int main()
{
    float C , F;

    std::cin >> C ;

    F = C * 1.8 + 32 ;

    if(F <= 32)
        { std::cout << "It is cold out" ; }
    else if(F > 32 && F <= 65)
        { std::cout << "Wear a jacket" ; }
    else
        { std::cout << "It is nice out" ; }

}