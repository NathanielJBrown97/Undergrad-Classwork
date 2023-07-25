#include <iostream>

int main()
{
    char single_character;
    std::cin >> single_character;

    int number_rows = single_character - 'A' + 1;

    for (int current_row = 0; current_row < number_rows; current_row++)
    {
        for (int space = 0; space < number_rows - current_row - 1; space++)
        {
            std::cout << "  ";
        }

        for (int forward_letter = 0; forward_letter <= current_row; forward_letter++)
        {
            if (forward_letter == 0)
            {
                std::cout << char('A' + forward_letter);
            }
            else
            {
                std::cout << " " << char('A' + forward_letter);
            }
        }

        for (int reverse_letter = current_row - 1; reverse_letter >= 0; reverse_letter--)
        {
            std::cout << " " << char('A' + reverse_letter);
        }
        std::cout << std::endl;
    }
}
