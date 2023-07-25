#include "cellgrid.h"
#include <iostream>
#include <fstream>
using namespace std;

// reads a file containing 1's and 0's and the dimesnsions to expect and
// creates a Cellgrid object
Cellgrid::Cellgrid(const char *fname, int m, int n)
{
    // assign row and col counters
    rows = m;
    cols = n;

    // create the grid on the heap, this will have to be deallocated later in
    // the destructor
    grid = new bool[rows * cols];

    // create a file reader stream to read data from a file
    ifstream infile;

    // open a stream to the given file
    infile.open(fname);

    // we are using row-major order in order to store this grid in 1D
    // instead of accessing grid like grid[a][b], we instead do:
    // grid[(a * number of columns) + b]
    for (int i = 0; i < rows; i++)
    {
        // calculate "(a * number of columns)" from above
        // in order to save some unnecessary computation
        int base = i * cols;
        for (int offset = 0; offset < cols; offset++)
        {
            // read data from filestream and store it in grid
            infile >> grid[base + offset];
        }
    }

    // close the filestream once we are done with it
    infile.close();
}

// destruct object where not implicit to the program
Cellgrid::~Cellgrid()
{
    // since we allocated memory on the heap, we must deallocate that memory
    delete[] grid;
}

// Helper function to check if a cell is valid and part of the same blob
bool Cellgrid::isValidCell(int row, int col, bool visited[], bool val)
{
    // Check if the cell is within the grid bounds
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        // if out of bounds flag invalid cell (i.e. no blob)
        return false;

    // Check if the cell has already been visited or if it is not part of the same blob
    if (visited[row * cols + col] || grid[row * cols + col] != val)
        // if so flip flag false
        return false;

    // If the cell is valid and part of the same blob flip flag true
    return true;
}

// countCells helper function passed row/col/ bool visited array, and connection type
int Cellgrid::countCellsHelper(int row, int col, bool visited[], int conn)
{
    // Mark the cell as visited
    visited[row * cols + col] = true;

    // Initialize the count to 1 for the starting cell
    int count = 1;

    // if connection type 4
    if (conn == 4)
    {
        // Check the 4 adjacent cells
        // arrays to store changes in row/col indexes for 4 adjacent cells
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {-1, 0, 1, 0};

        // loop through adjacent cells
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            // if adjacent cell is valid and in same blob
            if (isValidCell(nrow, ncol, visited, grid[row * cols + col]))
            {
                // add the count of this to our counter.
                count += countCellsHelper(nrow, ncol, visited, conn);
            }
        }
    }
    // otherwise it'll be connection type 8
    else
    {
        // Check the 8 adjacent cells
        // arrays to store positional changes for the 8 adjacent cells
        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        // loop through adjacent cells
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            // if adjacent is valid and same blob
            if (isValidCell(nrow, ncol, visited, grid[row * cols + col]))
            {
                // add its count to the current count
                count += countCellsHelper(nrow, ncol, visited, conn);
            }
        }
    }

    // finally return count for output
    return count;
}
// this is the function call which will be made by the autograder to test
// your implementation for problem 1. (row, col) is the "start point" for
// counting the cells, conn is the type of connection to consider (4 or 8).
int Cellgrid::countCells(int row, int col, int conn)
{
    // check if the starting cell is out of bounds or if it is not a filled cell
    if (row < 1 || row > rows || col < 1 || col > cols || !grid[(row - 1) * cols + (col - 1)])
    {
        return 0;
    }

    // mark the current cell as visited
    grid[(row - 1) * cols + (col - 1)] = false;

    // initialize a counter for the current blob and add the starting cell to it
    int count = 1;

    // check each neighbor of the current cell
    if (conn == 4)
    {
        // check 4-connected neighbors
        count += countCells(row - 1, col, conn); // up
        count += countCells(row + 1, col, conn); // down
        count += countCells(row, col - 1, conn); // left
        count += countCells(row, col + 1, conn); // right
    }
    else if (conn == 8)
    {
        // check 8-connected neighbors
        count += countCells(row - 1, col, conn);     // up
        count += countCells(row + 1, col, conn);     // down
        count += countCells(row, col - 1, conn);     // left
        count += countCells(row, col + 1, conn);     // right
        count += countCells(row - 1, col - 1, conn); // up left
        count += countCells(row - 1, col + 1, conn); // up right
        count += countCells(row + 1, col - 1, conn); // low left
        count += countCells(row + 1, col + 1, conn); // low right
    }

    // return the total count of cells in the current blob
    return count;
}
// this is the funciton call which will be made by the autograder to test
// your implementation for problem 2. conn is the type of connection
// to consider (4 or 8).
int Cellgrid::countBlobs(int conn)
{
    // blob counter at 0
    int blobCount = 0;
    // array to track which cells have been visted
    bool visited[rows * cols] = {false};

    // outer loop through rows
    for (int row = 0; row < rows; row++)
    {
        // inner loop through cols
        for (int col = 0; col < cols; col++)
        {
            // If the cell has not been visited and it is part of a blob
            if (!visited[row * cols + col] && grid[row * cols + col])
            {
                // Increase the blob count and call countCellsHelper to mark all cells in the blob as visited
                blobCount++;
                countCellsHelper(row, col, visited, conn);
            }
        }
    }
    // return blob counter
    return blobCount;
}

// this function prints your cellgrid in 2D format without trailing
// whitespace. Use this function to aid in debugging if you wish
void Cellgrid::print()
{
    for (int i = 0; i < rows; i++)
    {
        int base = i * cols;
        std::cout << grid[base];
        for (int offset = 1; offset < cols; offset++)
        {
            std::cout << ' ' << grid[base + offset];
        }
        std::cout << std::endl;
    }
}