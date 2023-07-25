#include <iostream>

int main(){
    int num, i = 0 ;
    std::cout << "How high should I count..." ;
    std::cin >> num ;

    while (i <= num){
        std::cout << i << std::endl ;
        i++ ;
    }
}