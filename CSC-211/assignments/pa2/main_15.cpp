#include <iostream>

int main()
{
    int number_of_pattern_rows_half;
    std::cin >> number_of_pattern_rows_half;

    // calculate the size of the rug
    int rugSize = number_of_pattern_rows_half * 4 + 2;

    // print the top border of the rug
    std::cout << "#";
    for (int i = 0; i < rugSize - 2; i++)
    {
        std::cout << "=";
    }
    std::cout << "#" << std::endl;

    // print the top half of the rug
    int dotsBefore = number_of_pattern_rows_half * 2 - 2;
    int dotsAfter = 0;
    for (int i = 0; i < number_of_pattern_rows_half; i++)
    {
        std::cout << "|";
        for (int j = 0; j < dotsBefore; j++)
        {
            std::cout << " ";
        }
        std::cout << "<>";
        for (int j = 0; j < dotsAfter; j++)
        {
            std::cout << ".";
        }
        std::cout << "<>";
        for (int j = 0; j < dotsBefore; j++)
        {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        dotsBefore -= 2;
        dotsAfter += 4;
    }

    // print the bottom half of the rug
    dotsBefore = 0;
    dotsAfter = number_of_pattern_rows_half * 4 - 4;
    for (int i = number_of_pattern_rows_half - 1; i >= 0; i--)
    {
        std::cout << "|";
        for (int j = 0; j < dotsBefore; j++)
        {
            std::cout << " ";
        }
        std::cout << "<>";
        for (int j = 0; j < dotsAfter; j++)
        {
            std::cout << ".";
        }
        std::cout << "<>";
        for (int j = 0; j < dotsBefore; j++)
        {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        dotsBefore += 2;
        dotsAfter -= 4;
    }

    // print the bottom border of the rug
    std::cout << "#";
    for (int i = 0; i < rugSize - 2; i++)
    {
        std::cout << "=";
    }
    std::cout << "#" << std::endl;

    return 0;
}