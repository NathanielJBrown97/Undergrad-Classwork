#include <iostream>
#include <string>
int main()
{
    int d , m , y , weekday ;
    std::string gradeScopesDumbassOutput ;
    std::cin >> d ;
    std::cin >> m ;
    std::cin >> y ;
    if(m == 1)
        { m = 13; y = y - 1; }
    if(m == 2)
        { m = 14; y = y - 1; }
    weekday = ( d + (((m+1)*26)/10) + ( y % 100 ) + ((y % 100)/4) + ((y / 100)/4) + 5 * (y /100) ) % 7 ;

    switch(weekday){
        case 0:
            gradeScopesDumbassOutput = "Saturday" ;
            break;
        case 1:
            gradeScopesDumbassOutput = "Sunday" ;
            break;
        case 2:
            gradeScopesDumbassOutput = "Monday" ;
            break;
        case 3:
            gradeScopesDumbassOutput = "Tuesday" ;
            break;
        case 4:
            gradeScopesDumbassOutput = "Wednesday" ;
            break;
        case 5: 
            gradeScopesDumbassOutput = "Thursday" ;
            break;
        case 6:
            gradeScopesDumbassOutput = "Friday" ;
    }
    std::cout << gradeScopesDumbassOutput ;
}