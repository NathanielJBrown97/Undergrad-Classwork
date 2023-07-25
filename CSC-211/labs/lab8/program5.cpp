#include <iostream>
int sum_digits(int n);

int sum_digits(int n)
{
    if (n <= 9)
    {
        std::cout << n;
    }
    else
    {
        sum_digits(n % 10) + sum_digits(n);
    }
}