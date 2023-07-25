#include <iostream>
#include <cmath>
#include <string>

int main() 
{
    int rawNum ;
    std::string bullshitGradescopeSolution;

    std::cin >> rawNum ;
    if(((rawNum < 0) || (rawNum > 9)))
        { std::cout << "Not a valid number" ; }

    switch (rawNum) {
        case 0:
            bullshitGradescopeSolution = "Zero" ;
            break;
        case 1:
            bullshitGradescopeSolution = "One" ;
            break;
        case 2:
            bullshitGradescopeSolution = "Two" ;
            break;
        case 3:
            bullshitGradescopeSolution = "Three" ;
            break;
        case 4:
            bullshitGradescopeSolution = "Four" ;
            break;
        case 5:
            bullshitGradescopeSolution = "Five" ;
            break;
        case 6:
            bullshitGradescopeSolution = "Six" ;
            break;
        case 7:
            bullshitGradescopeSolution = "Seven" ;
            break;
        case 8:
            bullshitGradescopeSolution = "Eight" ;
            break;
        case 9:
            bullshitGradescopeSolution =  "Nine" ;
            break;
    }

    std::cout << bullshitGradescopeSolution ;
}