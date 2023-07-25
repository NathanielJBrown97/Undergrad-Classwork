#include "sudoku.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// reads a file containing a sudoku puzzle represented as
// 9 rows, each consisting of 9 comma-separated values
Sudoku::Sudoku(const char *fname)
{
    // create a file reader stream to read data from a file
    ifstream infile;

    // will store lines and numbers
    string line, number;

    // index to write value to in puzzle
    int i = 0;

    // open a stream to the given file
    infile.open(fname);

    // get a line of input from the file
    while (getline(infile, line))
    {
        // store the line inside a stringstream
        stringstream parser(line);
        // use stringstream to split line along ','
        while (getline(parser, number, ','))
        {
            // convert string to an integer, store it, and update iterator
            puzzle[i++] = stoi(number);
        }
    }
    // close the filestream once we are done wiht it
    infile.close();
}

// destruct Sudoku object
Sudoku::~Sudoku()
{
    // since we never allocated any memory on the heap, we don't need
    // to define behavior for the deconstructor
}
// Check if a value is valid to be placed in a given position
bool Sudoku::isValid(int row, int col, int value) const
{
    // Check if value is already present in the row or column
    for (int cur_check = 0; cur_check < 9; cur_check++)
    {
        // if either row or column is equal to value
        if (puzzle[row * 9 + cur_check] == value || puzzle[cur_check * 9 + col] == value)
        {
            // false flag
            return false;
        }
    }

    // Check if value is already in the 3x3 subgrid
    // starting row of subgrid
    int subgrid_row = row - row % 3;
    // starting col of subgrid
    int subgrid_col = col - col % 3;
    // loop through rows of subgrid
    for (int cur_sub_row = subgrid_row; cur_sub_row < subgrid_row + 3; cur_sub_row++)
    {
        // loop through cols of subgrid
        for (int cur_sub_col = subgrid_col; cur_sub_col < subgrid_col + 3; cur_sub_col++)
        {
            // if equal to value
            if (puzzle[cur_sub_row * 9 + cur_sub_col] == value)
            {
                // flip flase flag
                return false;
            }
        }
    }
    // otherwise passes as true
    return true;
}

// Recursive helper function for backtracking
bool Sudoku::solveHelper(int index)
{
    // 9x9 grid = 81 slots; if index == 81
    if (index == 81)
    {
        // must be done return true
        return true;
    }

    // Calculate row and column for this index
    // index divided by 9 - row number
    int row = index / 9;
    // remainder of index by 9 - col number
    int col = index % 9;

    // If cell is prefilled; move to next
    if (puzzle[index] != 0)
    {
        // recall solveHelper with index incremented -->ReCurSiOn
        return solveHelper(index + 1);
    }

    // iterate through values to try all possible combinations
    for (int value = 1; value <= 9; value++)
    {
        // if its valid
        if (isValid(row, col, value))
        {
            // try this value
            puzzle[index] = value;

            // Recursively call solveHelper incremented index
            if (solveHelper(index + 1))
            {
                // return true
                return true;
            }

            // If this value doesn't work, backtrack and set index to 0.
            puzzle[index] = 0;
        }
    }

    // otherwise nothing worked return false
    return false;
}

// Solve the Sudoku puzzle using backtracking
void Sudoku::solve()
{
    // Call the helper function starting at the first position in the grid
    solveHelper(0);
}

// this function prints your puzzle in 2D format with commas
// separating your values
void Sudoku::print()
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << puzzle[i * 9];
        int base = i * 9;
        for (int offset = 1; offset < 9; offset++)
        {
            std::cout << ',' << puzzle[base + offset];
        }
        std::cout << std::endl;
    }
}