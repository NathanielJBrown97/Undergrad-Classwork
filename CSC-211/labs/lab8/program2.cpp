#include <iostream>
void print_arr(int *arr, int n);

void print_arr(int *arr, int n)
{
    if (n <= 1)
    {
        std::cout << arr[0];
        return;
    }
    else
    {
        std::cout << arr[0] << '\n';
        print_arr(arr + 1, n - 1);
    }
}