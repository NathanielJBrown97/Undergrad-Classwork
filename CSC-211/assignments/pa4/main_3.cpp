#include <iostream>

void eight_puzzle()
{
    // col and row values for scaleablity
    int col = 3, row = 3;
    // empty 2d board to be filled with user input
    int eight_board[row][col];

    // iterate through outer loop - i.e. rows
    for (int cur_row = 0; cur_row < row; cur_row++)
    {
        // iterate through the columns within each row
        for (int cur_col = 0; cur_col < col; cur_col++)
        {
            // ask for input of each position of the column (i.e. filling each position of the 2d array)
            std::cin >> eight_board[cur_row][cur_col];
        }
    }

    // ///////////////////////
    // //// START COPY HERE   ----------- PRINTS FOR CHECKING
    // // test print function
    // //  outer through the rows
    // for (int cur_row = 0; cur_row < row; cur_row++)
    // {
    //     // inner through the columns of each row
    //     for (int cur_col = 0; cur_col < col; cur_col++)
    //     {
    //         // output cur row/col position value.
    //         std::cout << eight_board[cur_row][cur_col] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // /// END COPY HERE    ----------- PRINTS FOR CHECKING
    // /////////////////////

    // variables to store position of our zero.
    int zero_row;
    int zero_col;

    // outer - iterate through rows
    for (int cur_row = 0; cur_row < row; cur_row++)
    {
        // inner - iterate through each column within the current row
        for (int cur_col = 0; cur_col < col; cur_col++)
        {
            // if the value boards cur row/col position is 0
            if (eight_board[cur_row][cur_col] == 0)
            {
                // update our variables to store the position of zero
                zero_row = cur_row;
                zero_col = cur_col;
                break;
            }
        }
    }

    // char for movement
    char move;
    // bool flag for when we're done taking input

    // while flag is false - loop input and move accordingly
    while (std::cin >> move)
    {
        // variables to reference the original position of zero and direct our shifts
        int new_row = zero_row;
        int new_col = zero_col;

        // if R increment col (goes right)
        if (move == 'R' || move == 'r')
        {
            new_col += 1;
        }
        // if L decrement col (goes left)
        else if (move == 'L' || move == 'l')
        {
            new_col -= 1;
        }
        // if U decrement row (goes up)
        else if (move == 'U' || move == 'u')
        {
            new_row -= 1;
        }
        // if D increment row (goes down)
        else if (move == 'D' || move == 'd')
        {
            new_row += 1;
        }
        // otherwise
        else
        {
            // swap flag to true, continue loop (ends loop)
            continue;
        }

        // check if our move was valid
        // if  new row and col are within the bounds of our grid (row/col = 3)
        if (new_row < 0 || new_row >= row || new_col < 0 || new_col >= col)
        {
            // continue taking input
            continue;
        }

        // swap empty space with adjacent value
        // temporary int to store value of our new row/col
        int temp = eight_board[new_row][new_col];
        // set our new row/col position to 0 (as we've moved the zero)
        eight_board[new_row][new_col] = 0;
        // replace the original zero_col/row values with our temp stored value above.
        eight_board[zero_row][zero_col] = temp;

        // redefine zero row/col for future use in loop.
        zero_row = new_row;
        zero_col = new_col;

        // ///////////////////////
        // //// START COPY HERE      ----------- PRINTS FOR CHECKING
        // // test print function
        // //  outer through the rows
        // for (int cur_row = 0; cur_row < row; cur_row++)
        // {
        //     // inner through the columns of each row
        //     for (int cur_col = 0; cur_col < col; cur_col++)
        //     {
        //         // output cur row/col position value.
        //         std::cout << eight_board[cur_row][cur_col] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // /// END COPY HERE      ----------- PRINTS FOR CHECKING
        // /////////////////////
    }

    /// correct board to compare
    int correct_board[3][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    // correct variable
    bool is_same = true;

    // loop through our rows
    for (int cur_row = 0; cur_row < row; cur_row++)
    {
        // loop through our columns within each row
        for (int cur_col = 0; cur_col < col; cur_col++)
        {
            // if the cur row/col of eight board != correctboards
            if (eight_board[cur_row][cur_col] != correct_board[cur_row][cur_col])
            {
                // flip flag and break
                is_same = false;
                break;
            }
        }
        // if flag was flipped, break outer
        if (!is_same)
        {
            break;
        }
    }
    // if is_same true output correct
    if (is_same)
    {
        std::cout << "Solution is good!" << std::endl;
    }
    // otherwise output no
    else
    {
        std::cout << "Wrong solution!" << std::endl;
    }
}

int main()
{
    eight_puzzle();
}