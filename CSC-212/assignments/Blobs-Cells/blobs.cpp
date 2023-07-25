//// Important note: This is a  modified version of my own work in CSC 211; from a very similar assignment.

#include <iostream>
#include <fstream>

////Class Definition
class Blob{
private:
    // private int variables to store num of rows and cols
    int rows, cols;
    // pointer to boolean grid to keep track
    bool *grid;
    // helper function to count individual cells
    int countCellsHelper(int cur_row, int cur_col, bool visited[], int connectionType);
    // helper to check if the cell is within a blob
    bool isThisInABlob(int cur_row, int cur_col, bool visited[], bool value);

public:
    //parameterized constructor; taking character file name and max row/cols
    Blob(const char *fileName, int maxRows, int maxCols);
    // deconstructor - only deletes grid
    ~Blob();
    //method to counts cells
    int countCells(int cur_row, int cur_col, int connectionType);
    // method to count blobs
    int countBlobs(int conn);
};
/// Parameterized Constructor
// Fills grid
Blob::Blob(const char *fileName, int maxRows, int maxCols){
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
/// Deconstructor
Blob::~Blob(){
    //only thing to delete is the grid we fill.
    delete[] grid;
}
/// Helper - Checks if its in a blob
// Helper function to check if a cell is valid and part of the same blob
bool Blob::isThisInABlob(int cur_row, int cur_col, bool visited[], bool value)
{
    // Check if in bounds
    // i.e. cur row is less than 0, or greater than or = to max rows. and vice versa for rows.
    if (cur_row < 0 || cur_row >= rows || cur_col < 0 || cur_col >= cols)
        // if any pass; its not in a blob return false
        return false;

    // checks if visited or within same blob in grid
    if (visited[cur_row * cols + cur_col] || grid[cur_row * cols + cur_col] != value)
        // if either is true; return false. not in a blob.
        return false;

    // if none of those checks flip; it must be in this blob.
    return true;
}
/// HELPER - for countCells
// countCells helper function passed row/col/ bool visited array, and connection type
int Blob::countCellsHelper(int cur_row, int cur_col, bool visited[], int connectionType) {
    // change the current cell to true
    visited[cur_row * cols + cur_col] = true;

    // count at 1 for starting cell
    int count = 1;
    //  std::cout << "Reading connection type as " << connectionType << "\n";

    // if connection type 4
    if (connectionType == 4) {
        // arrays to store index shifts in 4 cardinal directions rows/cols
        int adjacent_row[] = {0, 1, 0, -1};
        int adjacent_col[] = {-1, 0, 1, 0};

        // loop through adjacent cells
        for (int cur_position = 0; cur_position < 4; cur_position++) {
            // set new row and col for validity check
            int new_row = cur_row + adjacent_row[cur_position];
            int new_col = cur_col + adjacent_col[cur_position];
            // check if the new position is in a blob
            if (isThisInABlob(new_row, new_col, visited, grid[cur_row * cols + cur_col])) {
                // if true add 1 to counter
                count += countCellsHelper(new_row, new_col, visited, connectionType);
            }
        }

    }
    // if connection type is not 4; must be 8.
    else {
        // arrays to store index shifts in 8 cardinal directions
        int adjacent_row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int adjacent_col[] = {0, 1, 1, 1, 0, -1, -1, -1};
        // loop through adjacent cells
        for (int cur_position = 0; cur_position < 8; cur_position++) {
            // set new row and col for validity check
            int new_row = cur_row + adjacent_row[cur_position];
            int new_col = cur_col + adjacent_col[cur_position];
            // check if this new position is in a blob
            if (isThisInABlob(new_row, new_col, visited, grid[cur_row * cols + cur_col])) {
                // if true add 1 to counter
                count += countCellsHelper(new_row, new_col, visited, connectionType);
            }
        }
    }
    //return count
    return count;
}
/// Method to countCells
int Blob::countCells(int cur_row, int cur_col, int connectionType){
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
/// Count Blobs Method
int Blob::countBlobs(int connectionType){
    //   std::cout << "In countblobs conn type is " << connectionType << "\n";
    // counter set to 0
    int counter = 0;
    // array to track which cells have been visted
    bool* visited = new bool[rows * cols];
    // iterate through row*col (i.e. dimension of grid
    for (int iterator = 0; iterator < rows * cols; iterator++)
    {
        //set each position to false
        visited[iterator] = false;
    }
    // outer loop through rows
    for (int cur_row = 0; cur_row < rows; cur_row++)
    {
        // inner loop through cols
        for (int cur_col = 0; cur_col < cols; cur_col++)
        {
            // if cell is not in visited AND is part of a blob.
            if (!visited[cur_row * cols + cur_col] && grid[cur_row * cols + cur_col])
            {
                // incrememnt counter
                counter++;
                // count cells helper.
                countCellsHelper(cur_row, cur_col, visited, connectionType);
            }
        }
    }
    // return count of blobs
    return counter;
}

/// MAIN to call everything.
int main(int argc, char *argv[]){

    int maxRows, maxCols, connectionType;
    // char pointer of txt file name
    char *fileName = argv[1];

    // CLA pos 2 is rows
    maxRows = std::atoi(argv[2]);
    // CLA pos 3 is cols
    maxCols = std::atoi(argv[3]);
    // connection type from CLA pos 4
    connectionType = std::atoi(argv[4]);

//    std::cout << "In main connection type is " << connectionType << "\n";

    // create object; which will call a method to count blobs
    Blob gradescopeLikeMePlease(fileName, maxRows, maxCols);

    // call method and have it output for gradescope
    std::cout << gradescopeLikeMePlease.countBlobs(connectionType) << "\n";

}