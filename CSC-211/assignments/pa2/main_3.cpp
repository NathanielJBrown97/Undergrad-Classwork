#include <iostream>

int main()
{
    int get_factorial_of;
    long long factorial_value = 1;
    std::cin >> get_factorial_of;

    for (int countdown = get_factorial_of; countdown > 0; countdown--)
    {
        factorial_value *= countdown;
    }
    if (factorial_value > 2147483646 || factorial_value < -2147483646)
    {
        std::cout << "Can't handle this";
    }
    else
    {
        std::cout << factorial_value;
    }
}