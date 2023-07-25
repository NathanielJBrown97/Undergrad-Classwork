
#include "maze.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

void Maze::writeOutputFile(std::string outputFileName){
    //fstream create output file with our filename
    std::ofstream outputFile(outputFileName);

    //while open
    if (outputFile.is_open()) {
        //iterate through each row in vector
        for (int curRow = 0; curRow < numRows; curRow++){
            // for each row go through each column
            for (int curCol = 0; curCol < numCols; curCol++){
                //write the value of this vertice
                outputFile << decimalMaze[curRow][curCol] << " ";
            }
            // end line after each complete row (i.e. when col iteration stops
            outputFile << "\n"; // more effecient end line.
        }
        //close file
        outputFile.close();
    }
        //error just in-case for debug purposes.
    else {
        std::cout << "This is a notification that file: " << outputFileName << " could not be created, opened and written... \n";
    }

}
//may need to be passed the currentPos pair and the visited list. should have access to num row/col
void Maze::fillNeighbors(std::pair<int, int> a_currentCell, std::vector<std::pair<int,int>> visitedCells, std::vector<std::pair<int, int>> &whicheverNeighbors){
    std::cout << "Within fillNeighbors(), visitedCells are:  \n";
    for (size_t currentPair = 0; currentPair < visitedCells.size(); currentPair++){
        std::cout << visitedCells[currentPair].first << visitedCells[currentPair].second << "\n";
    }

    std::cout << "Within fillNeighbors(), unvisitedNeighbors are: \n";
    for (size_t currentNeighbor = 0; currentNeighbor < whicheverNeighbors.size(); currentNeighbor++){
        std::cout << whicheverNeighbors[currentNeighbor].first << whicheverNeighbors[currentNeighbor].second << "\n";
    }

    //variable for direction mods
    int northSouth = a_currentCell.first;
    int westEast = a_currentCell.second;

    std::cout << "Within fillNeighbors(): " << "\n" << "northSouth: " << northSouth << " westEast: " << westEast << "\n";
    // check if neighbors are valid and append in NSEW order

    ////ADD NORTH CELL
    //if current row value for N is within the border's bounds
    if ( a_currentCell.first > 0){
        std::cout << "checking north success... \n";
        // make variable for cell to north
        std::pair<int, int> checkNorthCell = std::make_pair(northSouth  -1 , westEast);
        std::cout << "checkNorthCell: " << checkNorthCell.first << checkNorthCell.second << "\n";
        // and is not yet visited
        if (std::find(visitedCells.begin(), visitedCells.end(), checkNorthCell) == visitedCells.end()){
            // push the checked northern cell to whichever neighbor vector has been passed
            whicheverNeighbors.push_back(checkNorthCell);
        }
        else{ std::cout << "N Neighbor in visited. \n";}
    }
    else{ std::cout << "Fill N Not Valid \n";}
    ////ADD SOUTH CELL
    //if current row value for S is within border's bounds (i.e. numRows)
    if ( a_currentCell.first+1 < numRows ){
        std::cout << "checking south success... \n";
        //make variable for cell to south
        std::pair<int, int> checkSouthCell = std::make_pair(northSouth +1, westEast);
        std::cout << "checkSouthCell: " << checkSouthCell.first << checkSouthCell.second << "\n";
        //and is not yet visited
        if (std::find(visitedCells.begin(), visitedCells.end(), checkSouthCell) == visitedCells.end()){
            //push the checked southern cell to whichever neighbor vector has been passed
            whicheverNeighbors.push_back(checkSouthCell);
        }
        else{ std::cout << "S Neighbor in visited. \n";}
    }else{ std::cout << "Fill S Not Valid \n";}
    ////ADD EAST CELL
    //if current col is within Eastern bounds (i.e. numCols)
    if (a_currentCell.second+1 < numCols){
        std::cout << "checking east success... \n";
        //make variable for cell to east
        std::pair<int,int> checkEastCell = std::make_pair(northSouth, westEast + 1);
        std::cout << "checkEastCell: " << checkEastCell.first << checkEastCell.second << "\n";
        //and is not yet visited
        if (std::find(visitedCells.begin(), visitedCells.end(), checkEastCell)== visitedCells.end()){
            //push the checked eastern cell to whichever neighbor vector has been passed
            whicheverNeighbors.push_back(checkEastCell);
        }
        else{ std::cout << "East Neighbor in Visited \n";}
    }else{ std::cout << "Fill E Not Valid \n";}
    ///ADD WEST CELL
    // if current col is within western bounds (i.e. always 0)
    if (a_currentCell.second > 0){
        std::cout << "checking west success... \n";
        // make variable for cell to west
        std::pair<int,int> checkWestCell = std::make_pair(northSouth, westEast - 1 );
        std::cout << "checkWestCell: " << checkWestCell.first << checkWestCell.second << "\n";
        // and it is not yet visited
        if (std::find(visitedCells.begin(), visitedCells.end(), checkWestCell)== visitedCells.end()){
            // poush the checked western cell into whichever neighbor vector
            whicheverNeighbors.push_back(checkWestCell);
        }else{ std::cout << "West Neighbor in visited. \n";}
    }else{ std::cout << "Fill W Not Valid \n";}
    std::cout << "Vector of possible neighbor selections INSIDE HELPER: \n";
    for (size_t currentNeighbor = 0; currentNeighbor < whicheverNeighbors.size(); currentNeighbor++){
        std::cout << whicheverNeighbors[currentNeighbor].first << whicheverNeighbors[currentNeighbor].second << "\n";
    }
    std::cout << "How many visited Cells by end of this fillNeighbor function? " << visitedCells.size() << " \n";
}
void Maze::deleteConnection(std::pair<int, int> a_currentCell, std::pair<int, int> the_nextCell){
    //lists to modify dec -> bin -> dec conversion
    std::string binaryArray[16] = {"0000", "0001", "0010", "0011",
                                   "0100", "0101", "0110", "0111",
                                   "1000", "1001", "1010", "1011",
                                   "1100", "1101", "1110", "1111"};
    int decimalArray[16] = {0, 1, 2, 3,
                            4, 5, 6, 7,
                            8, 9, 10, 11,
                            12, 13, 14, 15};
    std::cout << "MAZE DURING GENERATION - START OF DELETE CONNECTION: \n";
    for(int currentRow = 0; currentRow < numRows; currentRow++){
        for(int currentCol = 0; currentCol < numCols; currentCol++){
            std::cout << decimalMaze[currentRow][currentCol] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "INSIDE DELETE CONNECTION: \n";
    std::cout << "currentCell: " << a_currentCell.first << a_currentCell.second << "\n";
    std::cout << "nextCell: " << the_nextCell.first << the_nextCell.second << "\n";

    std::cout << "DecimalMaze for currentCell: " << decimalMaze[a_currentCell.first][a_currentCell.second] << "\n";
    std::cout << "DecimalMaze for nextCell: " << decimalMaze[the_nextCell.first][the_nextCell.second] << "\n";
    ////////////
    //Variables to store originalCell's dec val and nextCells val - these naturally double as index's
    int originalCellDecVal = decimalMaze[a_currentCell.first][a_currentCell.second];
    int nextCellDecVal = decimalMaze[the_nextCell.first][the_nextCell.second];
    std::cout << "originalCellDecVal = " << originalCellDecVal << "\n";
    std::cout << "nextCellDecVal = " << nextCellDecVal << "\n";

    ///////////
    //Variable to get string equivalent of Original and next Dec vals
    std::string originalCellBinVal = binaryArray[originalCellDecVal];
    std::cout << "current Cell's binary value: " << originalCellBinVal << "\n";
    std::string  nextCellBinVal = binaryArray[nextCellDecVal];
    std::cout << "next Cell's binary value: " << nextCellBinVal << "\n";
    //////////
    //Variables to determine NS or EW direction shift
    int northSouthShift = the_nextCell.first - a_currentCell.first;
    int westEastShift = the_nextCell.second - a_currentCell.second;
    std::cout << "North or South shift: " << northSouthShift << " \n";
    std::cout << "West or east shift: " << westEastShift << " \n";

    //// Conditionals to determine which wall needs to be removed
    //Check for North / South changes
    // if shift FROM CURRENT -> NEXT is SOUTH
    if ( northSouthShift > 0){
        std::cout << "north - south shift > 0 \n";
        //delete SOUTH wall in current
        originalCellBinVal[1] = '0';
        std::cout << "South delete for starting current cell... " << originalCellBinVal  << "\n";
        //delete NORTH wall in next
        nextCellBinVal[0] = '0';
        std::cout << "North delete for starting next cell... " << nextCellBinVal  << "\n";
    }
    // if shift FROM CURRENT -> NEXT is NORTH
    if ( northSouthShift < 0){
        std::cout << "north - south shift < 0 \n";

        // delete NORTH wall in current
        originalCellBinVal[0] = '0';
        std::cout << "north delete for starting current cell... " << originalCellBinVal  << "\n";
        // delete SOUTH wall next
        nextCellBinVal[1] = '0';
        std::cout << "south delete for starting next cell... " << nextCellBinVal  << "\n";

    }

    // if shift from CURRENT -> NEXT is EAST
    if ( westEastShift > 0){
        std::cout << "east west shift > 0 \n";

        //delete EAST wall in current
        originalCellBinVal[2] = '0';
        std::cout << "east delete for current cell... " << originalCellBinVal  << "\n";

        // delete WEST wall in next
        nextCellBinVal[3] = '0';
        std::cout << "west delete for  next cell... " << nextCellBinVal  << "\n";

    }
    // if shift from CURRENT -> NEXT is WEST
    if ( westEastShift < 0){
        std::cout << "east west shift < 0 \n";

        //delete WEST wall in current
        originalCellBinVal[3] = '0';
        std::cout << "west delete for starting current cell... " << originalCellBinVal  << "\n";

        //delete EAST wall in next
        nextCellBinVal[2] = '0';
        std::cout << "east delete for starting next cell... " << nextCellBinVal  << "\n";

    }
    ///// Now that wall values have been deleted:
    // Find index value of these new binary char strings
    int originalIndex;
    int nextIndex;
    //iterate through array
    for (int currentIndex = 0; currentIndex < 16; currentIndex++){
        // if current index of bin array == our binary string
        if ( binaryArray[currentIndex] == originalCellBinVal){
            // update original index val
            originalIndex = currentIndex;
            std::cout << originalIndex << "\n";
        }
        if ( binaryArray[currentIndex] == nextCellBinVal){
            //update next index val
            nextIndex = currentIndex;
            std::cout << nextIndex << "\n";
        }
    }

    // create var = the DECIMAL element at this index.
    int updateOriginalDec = decimalArray[originalIndex];
    int updateNextDec = decimalArray[nextIndex];
    //// UPDATE DECIMAL MAZE VALUE AT ORIGINAL AND NEXT X,Y.
    decimalMaze[a_currentCell.first][a_currentCell.second] = updateOriginalDec;
    decimalMaze[the_nextCell.first][the_nextCell.second] = updateNextDec;
}

void Maze::mazeGenerator() {
    std::cout << "numRows = " << numRows << " numCols = " << numCols << "\n";
    //condition for unique case of 1x1 grid
    if (numRows == 1) {
        if (numCols == 1) {
            decimalMaze[0][0] = 3;
            return;
        }
    }

    //set starting position to have open north wall & last position to have open south
    decimalMaze[0][0] = 7; //start N - Open
    decimalMaze[numRows - 1][numCols - 1] = 11; //end S - open

    std::cout << "MAZE BEFORE GENERATION \n";
    for (int currentRow = 0; currentRow < numRows; currentRow++) {
        for (int currentCol = 0; currentCol < numCols; currentCol++) {
            std::cout << decimalMaze[currentRow][currentCol] << " ";
        }
        std::cout << "\n";
    }
    //pair to track current pos
    std::pair<int, int> currentPosition(0, 0);

    //print starting currentPos
    std::cout << "Current Position: " << currentPosition.first << currentPosition.second << "\n";

    //Vector to contain all visited cells
    std::vector <std::pair<int, int>> visitedCells;
    visitedCells.push_back(currentPosition);

    //vector to contain 'A' array vals for the algorithm -- add starting point to end of arr
    std::vector <std::pair<int, int>> AlgArr;
    AlgArr.push_back(currentPosition);


    //Start Outer While Conditional -- i.e. while AlgArr is not empty
    while (!AlgArr.empty()) {
        std::cout << "is while alg running... yes \n";
        // set current position before removing from AlgArr
        std::pair<int, int> currentPosition = AlgArr.back();

        std::cout << "Current Position: " << currentPosition.first << currentPosition.second << "\n";

        //delete currentPos from AlgArr
        AlgArr.pop_back();

        //vector to contain unvisited neighbors
        std::vector <std::pair<int, int>> unvisitedNeighbors;
        std::cout << "Vector of possible neighbor selections outside the helper \n";
        for (size_t currentNeighbor = 0; currentNeighbor < unvisitedNeighbors.size(); currentNeighbor++) {
            std::cout << unvisitedNeighbors[currentNeighbor].first << unvisitedNeighbors[currentNeighbor].second
                      << "\n";
        }
        fillNeighbors(currentPosition, visitedCells, unvisitedNeighbors);


        for (size_t currentElement = 0; currentElement < unvisitedNeighbors.size(); currentElement++) {
            std::cout << "Current Neighbor Choices OUTSIDE OF HELPER: " << unvisitedNeighbors[currentElement].first
                      << unvisitedNeighbors[currentElement].second << "\n";
        }


        //if there are neighbors; randomly select one and re-iterate
        if (!unvisitedNeighbors.empty()) {
            // computation for rand selection according to rules
            int idx = std::rand() / ((RAND_MAX + 1u) / unvisitedNeighbors.size());
            // define selection as random element of unvisited neighbors
            std::pair<int, int> selection = unvisitedNeighbors[idx];
            std::cout << "Current Move Selection: " << selection.first << selection.second << "\n";

            // add selection to visited and AlgArr
            AlgArr.push_back(selection);
            visitedCells.push_back(selection);
            std::cout << "VisitedCells currently: \n";
            for (size_t curElm = 0; curElm < visitedCells.size(); curElm++) {
                std::cout << visitedCells[curElm].first << visitedCells[curElm].second << "\n";
            }
//// START DEBUGGING HERE
            //call delete connection helper to modify decimal value of the decMaze
            deleteConnection(currentPosition, selection);
        }
            //otherwise if visited count is not equal to maxrows x max cols, we havent explored fully
            // implement backtracking
        else if (static_cast<int>(visitedCells.size()) != numRows * numCols) {
            std::cout << visitedCells.size() << " <=== this is visitedCells size " << numRows * numCols << " <=== this is row x col value \n";
            // index of last element in visited
            int lastElement = visitedCells.size() - 1;
            //pair of last element in visited list
            std::pair<int, int> lastVisited = visitedCells[lastElement];
            std::cout << lastVisited.first << lastVisited.second << " <--- lastVisited within generation alg ( backtracking elseif) OUTSIDE WHILE \n";
            //vector for backtrack unvisited
            std::vector <std::pair<int, int>> backtrack_unvisitedNeighbors;

            while (backtrack_unvisitedNeighbors.empty() && lastElement >= 0) {
                std::pair<int, int> lastVisited = visitedCells[lastElement];
                std::cout << lastVisited.first << lastVisited.second << " <--- lastVisited within generation alg ( backtracking elseif) \n";
                //decrement from last index - bc last element has no neighbors, or we wouldnt be in this elif

                std::cout << lastElement << " last element position value in while... (backtrack) \n";
                std::cout << lastVisited.first << lastVisited.second << " LastVisited pair being passed to fill neighbor... \n";
                //fill neighbors passed the new backtracked last element
                std::cout << "==== THIS IS A BACKTRACK FILL NEIGHBOR ATTEMPT: \n";
                fillNeighbors(lastVisited, visitedCells, backtrack_unvisitedNeighbors);
                lastElement -= 1;
            }

            // computation for rand selection according to rules
            int idx = std::rand() / ((RAND_MAX + 1u) / backtrack_unvisitedNeighbors.size());

            for (size_t currentElement = 0; currentElement < backtrack_unvisitedNeighbors.size(); currentElement++) {
                std::cout << "Current Neighbor Choices OUTSIDE OF backtrack while loop: " << backtrack_unvisitedNeighbors[currentElement].first
                          << backtrack_unvisitedNeighbors[currentElement].second << " \n";
            }

            // define selection as random element of unvisited neighbors
            std::pair<int, int> selection = backtrack_unvisitedNeighbors[idx];
            // add selection to visited and AlgArr
            AlgArr.push_back(selection);
            visitedCells.push_back(selection);
            //call delete connection helper to modify decimal value of the decMaze
            deleteConnection(lastVisited, selection);
        }
    }

    std::cout << "MAZE AFTER GENERATION \n";
    for (int currentRow = 0; currentRow < numRows; currentRow++) {
        for (int currentCol = 0; currentCol < numCols; currentCol++) {
            std::cout << decimalMaze[currentRow][currentCol] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Did we finish? Yes.";
}