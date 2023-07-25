#include <iostream>

bool is_number_prime()
{
    int number, i = 2;
    std::cin >> number;
    if (number < 2)
    {
        return false;
    }
    while (i < number / 2)
    {
        int remainder = number % i;
        if (remainder == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    if (is_number_prime() == 0)
    {
        std::cout << "False";
    }
    else
    {
        std::cout << "True";
    }
}