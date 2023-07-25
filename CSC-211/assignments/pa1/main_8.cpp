#include <iostream>
#include <bits/stdc++.h>
#include <string>
int main()
{
    int number , wasNeg ;
    std::string bad = " is no good" ;
    std::cin >> number ;
    

    if(number < 0)
        { number = number * -1 ; wasNeg = 1 ;}

    int isNine = number % 10 ;

    if(isNine == 9 )
        { bad = " is good";}

    if(wasNeg == 1)
        { number = number * - 1 ;}

    std::cout << number << bad ;

    
}