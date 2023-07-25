#include <iostream>

int main(){
    int a , b , c , d ;
    std::cin >> a ;
    std::cin >> b ;
    std::cin >> c ;

    if( a < b ){
        d = a ;
        if(c < a){
            d = c ;
        }
    }
    else if(b < a){
        d = b ;
        if(c < b){
            d = c;
        }
    }
    std::cout << "The smallest number entered was " << d ;
}