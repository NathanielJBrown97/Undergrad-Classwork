#include <iostream>

int main()
{
    int number_of_rows;
    std::cin >> number_of_rows;
    // row draws
    for (int current_row = 0; current_row < number_of_rows; current_row++)
    {
        // space draws
        for (int space = 0; space < number_of_rows - current_row - 1; space++)
        {
            std::cout << " ";
        }
        // astrix draws
        for (int astrix = 0; astrix <= current_row; astrix++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}