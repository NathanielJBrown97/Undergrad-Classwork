#include <iostream>

int squirrelBrainRoute(int a, int b, int c){
    bool isEven = false;
    int sum = 0, prod = 1;
    //determine odd or even
    if(a % 2 == 0){
        isEven = true;
    }
    //if a true >>>> sum function
    if(isEven == true){
        b++;
        while (b < c ) {
            sum += b;
            b++;
        }
    return sum;
    }

    // ELSE FALSE >>>> prod function
    else{
        b++;
        while(b < c){
            prod = prod * b;
            b++;
        }
    return prod;
    }
}

int main(){
    std::cout << squirrelBrainRoute(3,3,9);
}