#include <iostream>
unsigned int fact(int n)
{
    if (n < 2)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int main()
{
    std::cout << fact(5);
}