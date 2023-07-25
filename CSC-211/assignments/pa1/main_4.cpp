#include <iostream>
int main()
{
    int a , b , d;
    char c ;
    std::cin >> a ;
    std::cin >> b ;
    std::cin >> c ;
    if(c == '+')
    { 
        d = a + b ;
        std::cout << a << " " << c << " " << b << " = " << d ;
    }
    if(c == '-')
    { 
        d = a - b ;
        std::cout << a << " " << c << " " << b << " = " << d ;
    }
    if(c == '/')
    { 
        d = a / b ;
        std::cout << a << " " << c << " " << b << " = " << d ;
    }
    if(c == '*')
    { 
        d = a * b ;
        std::cout << a << " " << c << " " << b << " = " << d ;
    }
    return 0;
}