#include <iostream>

int main()
{
    int number_of_rows;
    std::cin >> number_of_rows;

    for (int current_row = 0; current_row < number_of_rows; current_row++)
    {
        for (int astrix = 0; astrix <= current_row; astrix++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}