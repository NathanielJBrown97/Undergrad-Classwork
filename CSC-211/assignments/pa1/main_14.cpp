#include <iostream>
#include <string>
int main(){
    double x , y ;
    std::cin >> x ;
    std::cin >> y ;

    if(x > 0 && y > 0 )
        { std::cout << "Quadrant 1" ; }
    else if(x < 0 && y > 0)
        { std::cout << "Quadrant 2" ; }
    else if(x > 0 && y < 0) 
        { std::cout << "Quadrant 4" ; }
    else if(x < 0 && y < 0)
        { std::cout << "Quadrant 3" ; }
    else if(x == 0 || y == 0)
        { std::cout << "No quadrant" ; }
}