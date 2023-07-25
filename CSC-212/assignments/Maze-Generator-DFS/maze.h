
//
// Created by obses on 5/25/2023.
//

#ifndef COMPSCI_MAZE_H
#define COMPSCI_MAZE_H
#include <vector>
#include <string>


class Maze {
public:
    Maze(int numRows, int numCols) : numRows(numRows), numCols(numCols) {
        decimalMaze.resize(numRows, std::vector<int>(numCols, 15));
    }
    void deleteConnection(std::pair<int, int> a_currentCell, std::pair<int, int> the_nextCell);
    void fillNeighbors(std::pair<int, int> a_currentCell, std::vector<std::pair<int, int>> visitedCells, std::vector<std::pair<int, int>> &whicheverNeighbors);
    void mazeGenerator();
    void writeOutputFile(std::string outputFileName);

private:
    int numRows;
    int numCols;
    std::vector<std::vector<int>> decimalMaze;
};


#endif //COMPSCI_MAZE_H
