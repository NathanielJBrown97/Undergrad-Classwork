#include <iostream>

int main()
{
    long long number, power_of, number_power_of = 1;
    std::cin >> number;
    std::cin >> power_of;
    for (long long i = 0; i < power_of; i++)
    {
        number_power_of *= number;
    }

    std::cout << number_power_of;
}