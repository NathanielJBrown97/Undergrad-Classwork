#include <iostream>


int main(){
    int a1 , a2 , a3 , sum;
    std::cin >> a1 ;
    std::cin >> a2 ;
    std::cin >> a3 ;

    sum = a1 + a2 + a3;

    if(sum != 180)
        {std::cout << "This triangle is impossible"; }
    if(a1 < 90 && a2 < 90 && a3 < 90)
        {std::cout << "Acute"; }
    if(a1 > 90 || a2 > 90 || a3 > 90)
        {std::cout << "Obtuse"; }
    if(a1 == 90 || a2 == 90 || a3 == 90)
        {std::cout << "Right";}

}