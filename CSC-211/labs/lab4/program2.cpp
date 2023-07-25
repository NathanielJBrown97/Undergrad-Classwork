#include <iostream>

int main(){
    for(;;){
        int input;
        std::cout << "Enter a number to print... (Press Zero 0; to exit.): " ;
        std::cin >> input ;
        std::cout << input ;
        if(input == 0){
            break;
        }
    }
}