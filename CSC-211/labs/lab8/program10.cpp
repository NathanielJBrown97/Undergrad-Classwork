#include <iostream>

bool is_sorted(int *array, int number)
{
    if (number <= 1)
    {
        return true;
    }
    if (array[0] < array[1])
    {
        return is_sorted(array + 1, number - 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    int array[] = {1, 2, 6, 4, 5};
    int number = sizeof(array) / sizeof(array[0]);

    if (is_sorted(array, number))
    {
        std::cout << "Array is in increasing order.";
    }
    else
    {
        std::cout << "Array is not in increasing order.";
    }
}