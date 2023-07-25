#include <iostream>
void returnNumDigits(std::string alphabetNumber){
    int numberDigits = alphabetNumber.length();
    std::cout << numberDigits << std::endl;
}

int main(){
    std::string alphabetNumber;
    std::cout << "Please enter the number you would like the total digits of... " << std::endl;
    std::cin >> alphabetNumber; std::cout << std::endl;
    returnNumDigits(alphabetNumber);
}