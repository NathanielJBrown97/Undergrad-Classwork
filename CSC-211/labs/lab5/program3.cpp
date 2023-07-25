#include <iostream>

int decimalConvertBinary(int decimal) {
    int binary = 0;
    int remainder, i = 1;

    while(decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * i;
        i *= 10;
    }
    return binary;
}

int main(){
    std::cout << decimalConvertBinary(6);
}