
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "maze.h"

int main(int argc, char* argv[]) {
    // extract seed val and generate said seed
    int seed = strtol(argv[1], nullptr, 10);
    std::srand(seed);
    // extract num of cols and rows
    int numRows = strtol(argv[2], nullptr, 10);
    int numCols = strtol(argv[3], nullptr, 10);
    std::cout << "IN MAIN: Rows = " << numRows << " Cols = " << numCols << "\n";
    // extract filename
    std::string outputFileName = std::string(argv[4]);


    //create obj of Maze class
    Maze pleaseWork(numRows, numCols);


    //call maze generation function
    pleaseWork.mazeGenerator();

    //call function to output maze int vals into txt file
    pleaseWork.writeOutputFile(outputFileName);

}
