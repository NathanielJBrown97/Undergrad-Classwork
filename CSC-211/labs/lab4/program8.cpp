#include<iostream>
int main()
{
    int n = 4, i, j, num = 1, space;
    space = n - 1;
    for ( j = 1 ; j <= n ; j++ ) {
        num = j;
        for ( i = 1 ; i <= space ; i++ )
            std::cout << " ";
  
        space --;
        for ( i = 1 ; i <= j ; i++ ){
            std::cout << num;
            num++;
        }
        num--;
        num--;
        for ( i = 1 ; i < j ; i++){
        std::cout << num;
            num--;
        }
        std::cout << "\n";
    }

}