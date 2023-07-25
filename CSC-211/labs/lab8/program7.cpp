#include <iostream>

int sum(int *array, int number)
{
    if (number == 0)
    {
        return 0;
    }
    else
    {
        return array[number - 1] + sum(array, number - 1);
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int number = sizeof(array) / sizeof(array[0]);

    std::cout << sum(array, number);
}