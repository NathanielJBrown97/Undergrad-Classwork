#include <iostream>

void replace(int array[], int size, int x, int n)
{
    // Sort the array using insertion sort algorithm
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

    // Replace all instances of x with n
    for (int i = 0; i < size; i++)
    {
        if (array[i] == x)
        {
            array[i] = n;
        }
    }
}

int main()
{
    int array[7] = {3, 1, 4, 1, 5, 9, 2};
    int size = 7;
    int x = 1;
    int n = 7;

    replace(array, size, x, n);

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}
