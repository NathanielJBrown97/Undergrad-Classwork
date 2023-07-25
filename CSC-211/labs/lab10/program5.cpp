#include <iostream>

void doubleEvens(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            array[i] = array[i] * 2;
        }
    }
}

int main()
{
    int array[5] = {1, 2, 3, 4, 8};
    int size = 5;

    doubleEvens(array, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}
