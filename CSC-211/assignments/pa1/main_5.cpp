#include <iostream>
#include <string>
/*INPUT NUMBER, OUTPUT IN 1 LINE EVEN OR ODD*/
int main() {
    int number ;
    std::cin >> number ;

    (number % 2 == 0) ? std::cout << number << " is even" : std::cout << number << " is odd";

    return 0;
}