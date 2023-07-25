#include <iostream>
#include <iomanip>

int main() {
    double n1 , n2 , n3 , avg ;
    std::cin >> n1 ;
    std::cin >> n2 ;
    std::cin >> n3 ;
    avg = ((n1 + n2 + n3) / 3 ) ;

    std::cout << "The average of " ;
    std::cout << std::fixed << std::setprecision(4) << n1 << ", " << n2 << ", and " << n3 << " is " << avg ;


//    std::cout << "The average of " ;
//    printf("%.4f" , n1);
  //  std::cout << ", " ;
//    printf("%.4f" , n2);
//    std::cout << ", and " ;
//    printf("%.4f" , n3);
//    std::cout << " is " ;
//    printf("%.4f" , ((n1+n2+n3)/3)); 






}