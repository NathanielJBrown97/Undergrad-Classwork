#include <iostream>

int fib(int number)
{
    if (number == 0 || number == 1)
    {
        if (number == 0)
        {
            return 0;
        }
        if (number == 1)
        {
            return 1;
        }
    }
    else
    {
        return fib(number - 1) + fib(number - 2);
    }
}

int main()
{
    std::cout << fib(12);
}