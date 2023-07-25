#include <iostream>

int findMax(int array[], int size)
{
    int maximum = array[0];
    int max_index = 0;

    for (int i = 1; i < size; i++)
    {
        if (array[i] > maximum)
        {
            maximum = array[i];
            max_index = i;
        }
    }

    return max_index;
}

int main()
{
    int array[5] = {3, 2, 1, 5, 4};
    int size = 5;
    std::cout << findMax(array, size);
}