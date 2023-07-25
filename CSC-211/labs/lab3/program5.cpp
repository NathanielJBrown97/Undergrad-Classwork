#include <iostream>

int main() {
    int input ;
    std::cin >> input ;

    if(input % 2 > 0){
        std::cout << "is odd" << std::endl  ;
    }
    if(input % 2 == 0){
        std::cout << "is even" << std::endl ;
        std::cout << "is divisible by 2" << std::endl ;
    }
    if(input % 3 == 0){
        std::cout << "is divisible by 3" << std::endl ;
    }
}