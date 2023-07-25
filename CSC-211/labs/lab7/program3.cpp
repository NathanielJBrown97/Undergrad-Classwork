#include <iostream>
const int arrSize = 3;

void fillArray(int arr[][arrSize]);
void printArray(int arr[][arrSize]);

int main()
{
    int myArr[arrSize][arrSize];

    printArray(myArr);
    fillArray(myArr);
    printArray(myArr);
}

void fillArray(int arr[][arrSize])
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            arr[i][j] = j;
        }
    }
}

void printArray(int arr[][arrSize])
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}