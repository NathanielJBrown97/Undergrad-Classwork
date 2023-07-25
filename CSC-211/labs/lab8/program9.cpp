// Doesn't work entirely. It's printing wonky.

#include <iostream>

void print_chars(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << c;
    }
}

void pyr(int levels, int current_level)
{
    if (current_level <= levels)
    {
        int num_chars = current_level <= levels / 2 ? current_level : 2 * (levels - current_level) + 2;
        print_chars('+', num_chars);
        std::cout << std::endl;
        pyr(levels, current_level + 1);
    }
}

int main()
{
    pyr(3, 1);
    return 0;
}
