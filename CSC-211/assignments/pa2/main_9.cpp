#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a < 0 || a > 20 || b < 0 || b > 20 || c < 0 || c > 20)
    {
        std::cin >> a >> b >> c;
    }
    if (a > b)
    {
        std::cin >> a;
    }
    bool dumbass_solution_length_greater_than_b = false;
    int length_of_row = a;
    while (length_of_row <= b)
    {

        // prints the inital + UNTIL you meet current length of row.
        for (int i = 0; i < length_of_row; i++)
        {
            std::cout << "+";
        }
        length_of_row += c;
        std::cout << std::endl;
    }
    // delete the 8 row cycle through till a below.

    if (length_of_row > b)
    {
        dumbass_solution_length_greater_than_b = true;
    }
    if (dumbass_solution_length_greater_than_b == true)
    {
        length_of_row = length_of_row - c;
    }
    if (dumbass_solution_length_greater_than_b == false)
    {
        length_of_row = length_of_row - 1;
    }
    while (length_of_row >= a)
    {
        for (int j = 0; j < length_of_row; j++)
        {
            std::cout << "+";
        }
        length_of_row -= c;
        std::cout << std::endl;
    }
}
