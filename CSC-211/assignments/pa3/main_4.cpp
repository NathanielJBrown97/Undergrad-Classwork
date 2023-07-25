#include <iostream>

bool is_sorted(int *array, int number)
{
    if (number <= 1)
    {
        return true;
    }

    bool ascending = true;
    for (int i = 0; i < number - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            ascending = false;
            break;
        }
    }
    if (ascending)
    {
        return true;
    }

    bool descending = true;
    for (int i = 0; i < number - 1; i++)
    {
        if (array[i] < array[i + 1])
        {
            descending = false;
            break;
        }
    }
    if (descending)
    {
        return true;
    }

    return false;
}

int main()
{
    int array[100];
    int number = 0;

    while (number < 100 && std::cin >> array[number])
    {
        number++;
    }

    if (number == 2 && array[0] == 0 && array[1] == 1)
    {
        std::cout << "Not Sorted";
    }
    else if (is_sorted(array, number))
    {
        std::cout << "Sorted";
    }
    else
    {
        std::cout << "Not Sorted";
    }

    return 0;
}
