#include <iostream>
#include <string>

int main()
{
    int number ;
    std::string PON ; 

    std::cin >> number ;

    if(number == 0)
        { PON = " is neither positive nor negative"; }
    else if (number > 0)
        { PON = " is positive"; }
    else 
        { PON = " is negative"; }

    std::cout << number << PON ;

}