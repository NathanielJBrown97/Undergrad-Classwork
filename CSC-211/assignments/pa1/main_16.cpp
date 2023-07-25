#include <iostream>
#include <string>
#include <iomanip>
int main()
{
    double temp , F , C ;
    std::string type ;
    std::cin >> temp ;
    std::cin >> type ;
    if(type == "C" || type == "F"){
        if(type == "C"){
             F = temp * 1.8 + 32.0 ;
             std::cout << std::fixed << std::setprecision(4)<< temp << " degree(s) " << type << " is equal to " << F << " degree(s) F" ;
        }
        else if(type == "F"){
            C = 5.0 * (temp - 32.0) / 9.0 ;
            std::cout << std::fixed << std::setprecision(4) << temp << " degree(s) " << type << " is equal to " << C << " degree(s) C" ;
        }
    }
}