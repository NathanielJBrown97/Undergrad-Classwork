//// Important note: This is a slightly modified version of my own work in CSC 211; from a very similar assignment.

#include <iostream>
#include <fstream>
class Cell{
private:
    // private int variables to store num of rows and cols
    int rows, cols;
    // pointer to boolean grid to keep track
    bool *grid;

public:
    //parameterized constructor; taking character file name and max row/cols
    Cell(const char *fileName, int maxRows, int maxCols);
    // deconstructor - only deletes grid
    ~Cell();
    //method to counts cells
    int countCells(int cur_row, int cur_col, int connectionType);

};
/// Parameterized Constructor
// Fills grid
Cell::Cell(const char *fileName, int maxRows, int maxCols){
    // sets rows/cols private member variables
    rows = maxRows;
    cols = maxCols;
    //set grid to a new array of size rows*cols
    grid = new bool[rows * cols];

    //ifstream to read file
    std::ifstream file;

    // open file
    file.open(fileName);
    //iterate through rows to max amount
    for (int cur_row = 0; cur_row < rows; cur_row++)
    {
        // calculate "(a * number of columns)" from above
        // in order to save some unnecessary computation
        int base = cur_row * cols;
        for (int cur_col = 0; cur_col < cols; cur_col++)
        {
            // put data from file into grid
            file >> grid[base + cur_col];
        }
    }
    // close file
    file.close();
}
// destruct object where not implicit to the program
Cell::~Cell()
{
    // since we allocated memory on the heap, we must deallocate that memory
    delete[] grid;
}


/// Method to countCells
int Cell::countCells(int cur_row, int cur_col, int connectionType){
    // if this cur row/col position is out of bounds; just return 0
    // check if the starting cell is out of bounds or if it is not a filled cell
    if (cur_row < 1 || cur_row > rows || cur_col < 1 || cur_col > cols || !grid[(cur_row - 1) * cols + (cur_col - 1)])
    {
        return 0;
    }


    // flip current position to false
    grid[(cur_row - 1) * cols + (cur_col - 1)] = false;

    // counter set to 1 to include this cell
    int count = 1;

    // if connection type 4
    if (connectionType == 4)
    {
        // check 4 cardinal directions and increment counter
        count += countCells(cur_row - 1, cur_col, connectionType); // up
        count += countCells(cur_row + 1, cur_col, connectionType); // down
        count += countCells(cur_row, cur_col - 1, connectionType); // left
        count += countCells(cur_row, cur_col + 1, connectionType); // right
    }
        // if connection type 8
    else if (connectionType == 8)
    {
        // check 8 cardinal directions and increment counters
        count += countCells(cur_row - 1, cur_col, connectionType);     // up
        count += countCells(cur_row + 1, cur_col, connectionType);     // down
        count += countCells(cur_row, cur_col - 1, connectionType);     // left
        count += countCells(cur_row, cur_col + 1, connectionType);     // right
        count += countCells(cur_row - 1, cur_col - 1, connectionType); // up left
        count += countCells(cur_row - 1, cur_col + 1, connectionType); // up right
        count += countCells(cur_row + 1, cur_col - 1, connectionType); // down left
        count += countCells(cur_row + 1, cur_col + 1, connectionType); // down right
    }

    // return the cell count.
    return count;
}

/// MAIN to call everything.
int main(int argc, char *argv[]){

    int maxRows, maxCols,start_row, start_col, connectionType;
    // char pointer of txt file name
    char *fileName = argv[1];

    // CLA pos 2 is rows
    maxRows = std::atoi(argv[2]);
    // CLA pos 3 is cols
    maxCols = std::atoi(argv[3]);
    //CLA pos 4 is start row, 5 is col
    start_row = std::atoi(argv[4]);
    start_col = std::atoi(argv[5]);
    // connection type from CLA pos 6
    connectionType = std::atoi(argv[6]);



//    std::cout << "In main connection type is " << connectionType << "\n";

    // create object; which will call a method to count blobs
    Cell gradescopeLikeMePlease(fileName, maxRows, maxCols);

    // call method and have it output for gradescope
    std::cout << gradescopeLikeMePlease.countCells(start_row, start_col, connectionType) << "\n";

}
