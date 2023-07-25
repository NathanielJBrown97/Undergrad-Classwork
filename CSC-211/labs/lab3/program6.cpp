#include <iostream>

int main(){
    int low , high , num ;
    std::cin >> low >> high >> num ;

    if(num >= low && num <= high){
        std::cout << "This is within range." ;
    }
    else{
        std::cout << "This is out of range." ;
    }
}