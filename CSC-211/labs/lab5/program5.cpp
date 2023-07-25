#include <iostream>
void reverseNumber(std::string alphabetNumber){
    int numberDigits = alphabetNumber.length();
    int numberNumber = stoi(alphabetNumber);
    for(int i = numberDigits; i >= 0; i--){
        std::cout << alphabetNumber[i] ;
    }
}

int main(){
    std::string alphabetNumber;
    std::cout << "Please enter the number you would like reversed... " << std::endl;
    std::cin >> alphabetNumber;
    reverseNumber(alphabetNumber);
}