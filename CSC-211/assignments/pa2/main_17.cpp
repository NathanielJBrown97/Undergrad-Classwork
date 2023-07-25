#include <iostream>

int main()
{
    int current_row, current_column;
    std::cin >> current_column >> current_row;
    // std::cout << "Row: " << current_row << " "
    //           << "Column: " << current_column << " " << std::endl;
    int current_move;

    while (std::cin >> current_move)
    {
        switch (current_move)
        {
        case 0:
            current_row += 1;
            current_column += 2;
            // std::cout << "Row: " << current_row << " "
            //           << "Column: " << current_column << " " << std::endl;

            // conditional to invalid sequence if out of bounds.
            if (current_row < 1 || current_row > 8 || current_column < 1 || current_column > 8)
            {
                std::cout << "Invalid sequence" << std::endl;
                return 0;
            }
            break;
        case 1:
            current_row -= 1;
            current_column += 2;
            // std::cout << "Row: " << current_row << " "
            //           << "Column: " << current_column << " " << std::endl;

            // conditional to invalid sequence if out of bounds.
            if (current_row < 1 || current_row > 8 || current_column < 1 || current_column > 8)
            {
                std::cout << "Invalid sequence" << std::endl;
                return 0;
            }
            break;
        case 2:
            current_row -= 2;
            current_column += 1;
            // std::cout << "Row: " << current_row << " "
            //           << "Column: " << current_column << " " << std::endl;

            // conditional to invalid sequence if out of bounds.
            if (current_row < 1 || current_row > 8 || current_column < 1 || current_column > 8)
            {
                std::cout << "Invalid sequence" << std::endl;
                return 0;
            }
            break;
        case 3:
            current_row -= 2;
            current_column -= 1;
            // std::cout << "Row: " << current_row << " "
            //           << "Column: " << current_column << " " << std::endl;

            // conditional to invalid sequence if out of bounds.
            if (current_row < 1 || current_row > 8 || current_column < 1 || current_column > 8)
            {
                std::cout << "Invalid sequence" << std::endl;
                return 0;
            }
            break;
        case 4:
            current_row -= 1;
            current_column -= 2;
            // std::cout << "Row: " << current_row << " "
            //           << "Column: " << current_column << " " << std::endl;

            // conditional to invalid sequence if out of bounds.
            if (current_row < 1 || current_row > 8 || current_column < 1 || current_column > 8)
            {
                std::cout << "Invalid sequence" << std::endl;
                return 0;
            }
            break;
        case 5:
            current_row += 1;
            current_column -= 2;
            // std::cout << "Row: " << current_row << " "
            //           << "Column: " << current_column << " " << std::endl;

            // conditional to invalid sequence if out of bounds.
            if (current_row < 1 || current_row > 8 || current_column < 1 || current_column > 8)
            {
                std::cout << "Invalid sequence" << std::endl;
                return 0;
            }
            break;
        case 6:
            current_row += 2;
            current_column -= 1;
            // std::cout << "Row: " << current_row << " "
            //           << "Column: " << current_column << " " << std::endl;

            // conditional to invalid sequence if out of bounds.
            if (current_row < 1 || current_row > 8 || current_column < 1 || current_column > 8)
            {
                std::cout << "Invalid sequence" << std::endl;
                return 0;
            }
            break;
        case 7:
            current_row += 2;
            current_column += 1;
            // std::cout << "Row: " << current_row << " "
            //           << "Column: " << current_column << " " << std::endl;

            // conditional to invalid sequence if out of bounds.
            if (current_row < 1 || current_row > 8 || current_column < 1 || current_column > 8)
            {
                std::cout << "Invalid sequence" << std::endl;
                return 0;
            }
            break;
        }
    }

    std::cout << current_column << " " << current_row << std::endl;
}
