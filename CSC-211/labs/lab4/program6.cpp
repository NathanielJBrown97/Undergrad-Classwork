#include <iostream>
#include <string>

int main() {
    std::string symbol = "*";

    for (int i = 1; i <= 8; ++i) {
        if(i % 2 == 1) {
            for(int j = 1; j <= i; ++j) {
                std::cout << symbol ;
            }
            std::cout << "\n" ;
        }
    }
}