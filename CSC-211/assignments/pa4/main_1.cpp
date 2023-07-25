#include <iostream>
#include <unordered_set>

void sudoku_check()
{
    int row = 9, col = 9;
    int sudoku_board[row][col];

    // outer loop - iterates through arrays
    for (int cur_row = 0; cur_row < row; cur_row++)
    {
        // inner loop iterates through columns
        for (int cur_col = 0; cur_col < col; cur_col++)
        {
            // takes input of current position in 2d array
            std::cin >> sudoku_board[cur_row][cur_col];
        }
    }

    // validity variable for later
    bool is_valid = true;

    // outer loop - iterates through rows while validity remains valid.
    for (int cur_row = 0; cur_row < row && is_valid; cur_row++)
    {
        // empty unordered set calling it subgrid_set
        std::unordered_set<int> subgrid_set;
        // inner loop - iterates through columns
        for (int cur_col = 0; cur_col < col; cur_col++)
        {
            // define subgrid_value as our cur row/col position's value
            int subgrid_value = sudoku_board[cur_row][cur_col];
            // conditional check if the count of our subgrid value is over 0.
            if (subgrid_set.count(subgrid_value) > 0)
            {
                // if it is, flip flag
                is_valid = false;
                break;
            }
            // insert each number in subgrid_val to the subgrid_set.
            subgrid_set.insert(subgrid_value);
        }
    }

    // check for duplicates in columns
    // outer - iterate through columns
    for (int cur_col = 0; cur_col < col && is_valid; cur_col++)
    {
        // unordered set called subgrid_set
        std::unordered_set<int> subgrid_set;
        // inner - iterate through columns
        for (int cur_row = 0; cur_row < row; cur_row++)
        {
            // cur subgrid val is equal to the current row/col positions value
            int subgrid_value = sudoku_board[cur_row][cur_col];
            // if the count of the value within the set is greater than 0
            if (subgrid_set.count(subgrid_value) > 0)
            {
                // flip flag
                is_valid = false;
                break;
            }
            // insert each value into the subgrid set.
            subgrid_set.insert(subgrid_value);
        }
    }

    // check for duplicates in sub-grids
    // size of subgrid
    int subgrid_size = 3;
    // iterate through each row; increment by subgrid size (skips blocks rather than each position)
    for (int cur_row = 0; cur_row < row && is_valid; cur_row += subgrid_size)
    {
        // iterate through each column; increment by subgrid size. (skips blocks rather than each position)
        for (int cur_col = 0; cur_col < col && is_valid; cur_col += subgrid_size)
        {
            // unordered set called subgrid
            std::unordered_set<int> subgrid_set;
            // iterate through each row within the subgrid
            for (int sub_row = cur_row; sub_row < cur_row + subgrid_size; sub_row++)
            {
                // itterate through each column within the sub grid
                for (int sub_col = cur_col; sub_col < cur_col + subgrid_size; sub_col++)
                {
                    // subgrid val is the current value in the sudoku board
                    int subgrid_value = sudoku_board[sub_row][sub_col];
                    // if count for subgrids value is > 0
                    if (subgrid_set.count(subgrid_value) > 0)
                    {
                        // there are duplicates, swap false.
                        is_valid = false;
                        break;
                    }
                    // insert value into the subgrid set.
                    subgrid_set.insert(subgrid_value);
                }
                // if not is_valid
                if (!is_valid)
                {
                    // break
                    break;
                }
            }
        }
    }

    // output result
    if (is_valid)
    {
        std::cout << "Solution is good!" << std::endl;
    }
    else
    {
        std::cout << "Wrong solution!" << std::endl;
    }
}

int main()
{
    sudoku_check();
}

//////////////////////////////////////////////////////////////
///// OLD VERSION BEFORE I REALIZED THERE WERE SUBGRIDS //////
//////////////////////////////////////////////////////////////
// #include <iostream>
// void sudoku_check()
// {
//     int row = 9, col = 9;
//     int sudoku_board[row][col];
//     // fill each position of the array
//     // iterate through rows
//     for (int cur_row = 0; cur_row < row; cur_row++)
//     {
//         // in each row iterate through columns
//         for (int cur_col = 0; cur_col < col; cur_col++)
//         {
//             // ask for input of cell
//             std::cin >> sudoku_board[cur_row][cur_col];
//         }
//     }

//     // check for duplicates in rows
//     // bool for later output
//     bool row_validity = false;
//     // iterate through rows
//     for (int cur_row = 0; cur_row < row; cur_row++)
//     {
//         // reset bool for each iteration
//         row_validity = false;
//         // iterate through columns in each row
//         for (int cur_col = 0; cur_col < col; cur_col++)
//         {
//             // iterate through columns to the right of the current row
//             for (int i = cur_col + 1; i < col; i++)
//             {
//                 // if there is a duplicate in row
//                 if (sudoku_board[cur_row][cur_col] == sudoku_board[cur_row][i])
//                 {
//                     // flag as true
//                     row_validity = true;
//                     break;
//                 }
//             }
//             // if flagged end loop
//             if (row_validity)
//             {
//                 break;
//             }
//         }
//         // if flagged
//         if (row_validity)
//         {
//             // break from main loop
//             break;
//         }
//     }

//     // check for duplicates in columns
//     bool column_validity = false;
//     // iterate through columns
//     for (int cur_col = 0; cur_col < col; cur_col++)
//     {
//         // reset bool for each iteration
//         column_validity = false;
//         // iterate through each row in columns
//         for (int cur_row = 0; cur_row < row; cur_row++)
//         {
//             // iterate through rows to below the current column.
//             for (int i = cur_row + 1; i < row; i++)
//             {
//                 // if there are duplicate values
//                 if (sudoku_board[cur_row][cur_col] == sudoku_board[i][cur_col])
//                 {
//                     // flip column flag and break
//                     column_validity = true;
//                     break;
//                 }
//             }
//             // if flag flipped
//             if (column_validity)
//             {
//                 // break from loop
//                 break;
//             }
//         }
//         // if flag flipped
//         if (column_validity)
//         {
//             // break from outer loop
//             break;
//         }
//     }

//     // check validity for outputs.
//     // if both are true; Wrong solution
//     if (row_validity && column_validity)
//     {
//         std::cout << "Wrong solution!" << std::endl;
//     }
//     // if both are false; Right solution
//     if (!row_validity && !column_validity)
//     {
//         std::cout << "Solution is good!" << std::endl;
//     }
//     // if rows is true, and columns is false; wrong solution
//     if (row_validity && !column_validity)
//     {
//         std::cout << "Wrong solution!" << std::endl;
//     }
//     // versa
//     if (!row_validity && column_validity)
//     {
//         std::cout << "Wrong solution!" << std::endl;
//     }
// }

// int main()
// {
//     sudoku_check();
// }