#include <iostream>
void number_pyramid_Byinput(int rows){
    int i, j, num = 1, space;
    space = rows - 1;
    for ( j = 1 ; j <= rows ; j++ ) {
        num = j;
        for ( i = 1 ; i <= space ; i++ )
            std::cout << " ";
  
        space --;
        for ( i = 1 ; i <= j ; i++ ){
            std::cout << num % 10;
            num++;
        }
        num--;
        num--;
        for ( i = 1 ; i < j ; i++){
        std::cout << num % 10;
            num--;
        }
        std::cout << "\n";
    }
}
int main(){
    number_pyramid_Byinput(7);
}
