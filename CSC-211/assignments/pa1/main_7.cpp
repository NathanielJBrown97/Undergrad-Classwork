#include <iostream>
#include <string>

int main() 
{
    int number ;
    std::string satisfy = " does not satisfy the criteria" ;

    std::cin >> number ;

    if(number % 8 == 0 && number > 100)
        { satisfy = " satisfies the criteria"; }

    std::cout << number << satisfy ;

}