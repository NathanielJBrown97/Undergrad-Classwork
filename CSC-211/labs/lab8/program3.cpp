#include <iostream>
#include <cstring>

void print_rev_arr(int *arr, int n)
{

    if (n <= 1)
    {
        std::cout << arr[n - 1] << std::endl;
        return;
    }

    else
    {
        print_rev_arr(arr + 1, n - 1);

        std::cout << arr[n - 1] << std::endl;
    }
}
