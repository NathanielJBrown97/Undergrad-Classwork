#include <iostream>


int main() {
    char input ;
    std::cin >> input ;
    if(input >= 'A' && input <= 'Z'){
        std::cout << "Upper Case" ; 
    }
    else {
        std::cout << "Lower Case" ;
    }
}