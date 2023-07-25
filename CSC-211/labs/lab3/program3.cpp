#include <iostream>

int main()
{
    int num , i , dud , notPog = 0;
    std::cout << "Enter Number: " ;
    std::cin >> num ;

    dud = num/2;
if(num == 0 || num == 1){
    std::cout << "Not Prime" ;
}
else if(num != 0 && num != 1) {
    for(i = 2; i <= dud; i++) {
        if(num % i == 0) {
        std::cout << "Not Prime" ; 
        notPog = 1 ; 
        break;
        }
    }
    if (notPog == 0){
        std::cout << "Prime" ;

    }
    
}
 

}