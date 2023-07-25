#include <iostream>
#include <string>

int main()
{
    int a , b , c , d , f ;
    std::string grade;
    std::cin >> grade;
    if(grade == "A" || grade == "a")
    { std::cout << "Excellent" ; }
    else if(grade == "B" || grade == "b")
    { std::cout << "Good" ; }
    else if(grade == "C" || grade == "c")
    { std::cout << "Average" ; }
    else if(grade == "D" || grade == "d")
    { std::cout << "Poor" ; }
    else if(grade == "F" || grade == "f")
    { std::cout << "Failing" ; }


}