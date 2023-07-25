#include <iostream>
int main()
{
    unsigned long long number;
    int sum = 0;
    std::cin >> number;
    while (number != 0)
    {
        int current_digit = number % 10;
        if (current_digit % 2 == 0)
        {
            sum += current_digit;
        }
        number /= 10;
    }
    std::cout << sum;
}