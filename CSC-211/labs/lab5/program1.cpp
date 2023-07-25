#include <iostream>

int add(int a, int b){
    return a + b;
}
int mult(int a, int b){
    int sum = 0;
    for(int i=0; i < b; i++){
        sum = sum + a;
    }
    return sum;
}
int exp(int a, int b){
    int curVal = a;
    for(int i=0; i < b-1; i++){
        curVal = curVal * a;
    }
    return curVal;
}

int main(){
    std::cout << exp(2,3) << std::endl;
    std::cout << mult(3, 5) << std::endl;
    std::cout << add(1, 10) << std::endl;
}