#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
int main(){
// defined using doubles to allow for proper digit count and precise outputs. Saves a Var for string output of angle type.
    double x1, x2, y1, y2, v1, v2 , dotProd, normdotProd;
    std::string type;

    std::cin >> x1 >> y1 >> x2 >> y2 ;
// define both vector lengths. Square root of x*x + y*y
    v1 = sqrt((x1*x1) + (y1*y1));
    v2 = sqrt((x2*x2) + (y2*y2)) ;
// determine angle type based off of dot product variable established below
    dotProd = (x1 * x2) + (y1 * y2) ;
// if dotProd is 0, perpendicular, if greater than 0 type, and any other scenario would be obtuse. Updates string variable contents.
    if(dotProd == 0){
        type = "Perpendicular" ;
    }
    else if(dotProd > 0){
        type = "Acute" ;
    }
    else {
        type = "Obtuse" ;
    }
//double variables to redefine orginal input values; divided by respective vector... for normalized dot prod functoin.
    double nx1 = x1/v1, nx2 = x2/v2, ny1 = y1/v1, ny2 = y2/v2 ;
// normalized dot product based on newly defiend functions
    normdotProd = ((nx1 * nx2)) + ((ny1 * ny2)) ;

//output as demanded by the overlord gradescope.
    std::cout << "Length of v1: " << std::fixed << std::setprecision(4) << v1 << std::endl ;
    std::cout << "Length of v2: " << std::fixed << std::setprecision(4) << v2 << std:: endl ;
    std::cout << "Their normalized dot product is " << std::fixed << std::setprecision(4) << normdotProd << " and they are " << type ;


}