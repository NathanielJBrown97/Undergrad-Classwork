#include <iostream>

unsigned int sum_from_one(int starting_number)
{
    if (starting_number == 1)
    {
        return 1;
    }
    else
    {
        return starting_number + sum_from_one(starting_number - 1);
    }
}

int main()
{
    std::cout << sum_from_one(10);
}