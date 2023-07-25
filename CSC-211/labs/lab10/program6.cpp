#include <iostream>

void multiModify(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    for (int i = 0; i < size; i++)
    {
        if (array[i] % 3 == 0)
        {
            array[i] *= 3;
        }
        if (array[i] % 2 == 0)
        {
            array[i] *= 2;
        }
    }
}

int main()
{
    int array[8] = {3, 6, 9, 2, 8, 7, 10, 12};
    int size = 8;

    multiModify(array, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
