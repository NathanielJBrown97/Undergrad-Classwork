#include<iostream>
int main(){
    int i = 0 , j = 0 , k = 0, l = 0, m=0;
    while(i < 1){
        while(j < 7){
            std::cout << "!!" ;
            j++;
        }
        std::cout << std::endl ;
        while(k <= 7){
            if(k == 0){
                std::cout << "\\" ;
                std::cout << "\\" ;
            }
            if(k > 1 && k < 7){
                std::cout << "!!" ;
            }
            if(k == 7){
                std::cout << "//" ;
            }
            k++;
        }
        std::cout << std::endl ;
        while(l <= 7){
            if(l == 0){
                std::cout << "\\" ;
                std::cout << "\\" ;
                std::cout << "\\" ;
                std::cout << "\\" ;
            }

            if(l > 2 && l < 6){
                std::cout << "!!" ;
            }
            if(l == 6 || l == 7){
                std::cout << "//" ;
            }
            l++;
        }
        std::cout << std::endl;
        while(m <= 7){
            if(m == 0){
                std::cout << "\\" ;
                std::cout << "\\" ;
                std::cout << "\\" ;
                std::cout << "\\" ;
                std::cout << "\\" ;
                std::cout << "\\" ;
            }
            if(m > 3 && m < 5){
                std::cout << "!!" ;
            }
            if(m == 5 || m == 6 || m == 7){
                std::cout << "//";
            }
            m++;
        }
        i++;
    }
}

