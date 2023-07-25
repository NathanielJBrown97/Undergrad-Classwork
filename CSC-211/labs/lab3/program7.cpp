#include <iostream>

int main(){
    int a, b , c ;
    std::cout << "Enter Three Values" ;
    std::cin >> a >> b >> c ;
    if(a > b && a > c)
        {std::cout << a << "is the maximum vlaue." ;}
    if(b > a && b > c)
        {std::cout << b << "is the maximum vlaue." ;}
    if(c > b && c > a)
        {std::cout << c << "is the maximum vlaue." ;}
}