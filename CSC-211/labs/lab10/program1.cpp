#include <iostream>

int findMin(int array[], int size)
{
    int minimum = array[0];
    int i = 1;

    while (array[i] != size)
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
        i++;
    }

    return minimum;
}

int main()
{
    int array[5] = {3, 2, 1, 4, 5};
    int size = 5;
    std::cout << findMin(array, size);
}