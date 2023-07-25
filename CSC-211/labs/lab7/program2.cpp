#include <iostream>
#include <array>
void countEvens(int *total, int *array_of_numbers)
{

    if (int i = 0; i < 10)
    {
        if (array_of_numbers[i] % 2 == 0)
        {
            *total += 1;
        }
    }
}

int main()
{
    int array_of_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int total = 0;
    countEvens(&total, array_of_numbers);
    std::cout << total << std::endl;
}