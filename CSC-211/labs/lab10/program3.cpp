#include <iostream>

double calculateMedian(int array[], int size)
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
    // calculate the median
    if (size % 2 == 0)
    {
        // if the array has an even number of elements, return the average of the middle two
        return (array[size / 2 - 1] + array[size / 2]) / 2.0;
    }
    else
    {
        return array[size / 2];
    }
}

int main()
{
    int array[5] = {1, 2, 4, 6, 10};
    int size = 5;
    std::cout << calculateMedian(array, size);
}
