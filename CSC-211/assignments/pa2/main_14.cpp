#include <iostream>

int main()
{
    int test_perfect, sum = 0;
    std::cin >> test_perfect;

    for (int i = 1; i < test_perfect; i++)
    {
        if (test_perfect % i == 0)
        {
            sum += i;
        }
    }

    if (sum == test_perfect)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }
}