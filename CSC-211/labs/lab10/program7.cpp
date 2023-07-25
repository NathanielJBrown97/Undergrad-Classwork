#include <iostream>

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIdx])
            {
                minIdx = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIdx];
        array[minIdx] = temp;
    }
}

void split(int original[], int evens[], int odds[])
{
    int original_size = sizeof(original) / sizeof(original[0]);
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < original_size; i++)
    {
        if (original[i] % 2 == 0)
        {
            evens[evenCount++] = original[i];
        }
        else
        {
            odds[oddCount++] = original[i];
        }
    }

    // sort the even and odd arrays
    selectionSort(evens, evenCount);
    selectionSort(odds, oddCount);
}

int main()
{
    int original[] = {4, 1, 9, 7, 16, 3, 20, 36, 27};
    int original_size = sizeof(original) / sizeof(original[0]);
    int evens[original_size];
    int odds[original_size];

    split(original, evens, odds);

    std::cout << "Original array: ";
    for (int i = 0; i < original_size; i++)
    {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Even array: ";
    for (int i = 0; i < original_size; i++)
    {
        if (evens[i] != 0)
        {
            std::cout << evens[i] << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Odd array: ";
    for (int i = 0; i < original_size; i++)
    {
        if (odds[i] != 0)
        {
            std::cout << odds[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
