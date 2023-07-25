#include <iostream>
int main(){
    int sum = 0;
    
    int i = 1; 
    for ( i = 1 ; i <= 10 ; i++) {
        std::cout << sum ;
        if(i % 2 == 0){
            int j = 1 ;
            for(j = 1 ; j <= 5 ; j++){
                sum = sum + ( i  * j ) ;
            }
        }
        else{
            int j = 1;
            for(j=1 ; (10 - j) <= 5; j++){
                sum = sum + ( i * j ) ;
            }
        }
    }
}