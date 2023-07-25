#include <iostream>

int main() 
{
    int s ;
    std::cin >> s ;

    if(s > 55)
        {std::cout << "Speeding" ; }
    else if(s > 49 && s < 56)
        {std::cout << "Pushing your luck" ; }
    else
        {std::cout << "Safe" ; }
}