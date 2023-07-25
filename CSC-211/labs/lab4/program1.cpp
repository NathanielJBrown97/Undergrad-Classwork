#include <iostream>
int main(){
    int num ;
    std::cout << "How high do you want me to count..." ;
    std::cin >> num ; 
    for (int i = 0 ; i <= num ; ++i) {  
    std::cout << i << std::endl;
}
}