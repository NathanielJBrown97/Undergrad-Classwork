#include <iostream>
unsigned int fact(int n);

unsigned int fact(int n)
{
    if (n <= 1)
    {
        return n * 1;
    }
    else
    {
        n *fact(n - 1);
    }
}