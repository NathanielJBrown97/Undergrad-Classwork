#include <iostream>
#include <vector>

// function to count number of live neighbors for a given cell
int count_live_neighbors(std::vector<std::vector<char>> grid, int row, int col)
{
    // count starts at 0
    int alive_neighbors = 0;
    // outer loop through rows
    for (int cur_row = row - 1; cur_row <= row + 1; cur_row++)
    {
        // inner loop through cols
        for (int cur_col = col - 1; cur_col <= col + 1; cur_col++)
        {
            // if check if neighboring cell is within grid and not current cell
            if (cur_row >= 0 && cur_row < grid.size() && cur_col >= 0 && cur_col < grid[0].size() && !(cur_row == row && cur_col == col))
            {
                // if neighbor cell is alive increase alive_neighbors
                if (grid[cur_row][cur_col] == '*')
                {
                    alive_neighbors++;
                }
            }
        }
    }
    return alive_neighbors;
}

// function to simulate one generation of the game
std::vector<std::vector<char>> simulate_generation(std::vector<std::vector<char>> grid)
{
    // copy grid to change
    std::vector<std::vector<char>> new_grid = grid;
    // loop through each cel lin the grid
    // outer loop through rows
    for (int cur_row = 0; cur_row < grid.size(); cur_row++)
    {
        // inner loop through cols
        for (int cur_col = 0; cur_col < grid[0].size(); cur_col++)
        {
            // set variable to be the return of count neighbors function, passed grid and current row/col position.
            int live_neighbors = count_live_neighbors(grid, cur_row, cur_col);
            // start rules to each position in grid
            // if alive
            if (grid[cur_row][cur_col] == '*')
            {
                // less than 2 or more than 3 alive neighbors
                if (live_neighbors < 2 || live_neighbors > 3)
                {
                    // change to dead
                    new_grid[cur_row][cur_col] = '.';
                }
            }
            // if dead
            else
            {
                // and has 3 live neighbors
                if (live_neighbors == 3)
                {
                    // change to live.
                    new_grid[cur_row][cur_col] = '*';
                }
            }
        }
    }
    // return nthe new grid
    return new_grid;
}

int main()
{
    // rows/cols/gens variables and collect input.
    int num_of_rows, num_of_cols, num_of_generations;
    std::cin >> num_of_rows >> num_of_cols >> num_of_generations;
    // vectors for grid, passed rows and vector of number of cols
    std::vector<std::vector<char>> grid(num_of_rows, std::vector<char>(num_of_cols));
    // outter loop through rows
    for (int cur_row = 0; cur_row < num_of_rows; cur_row++)
    {
        // inner loop through cols
        for (int cur_col = 0; cur_col < num_of_cols; cur_col++)
        {
            // collect each value for position in groups
            std::cin >> grid[cur_row][cur_col];
        }
    }
    // loop through each generation
    for (int gen = 1; gen <= num_of_generations; gen++)
    {
        // update our grid to equal the returned grid from sim generation
        grid = simulate_generation(grid);
    }
    // ouput the final generation
    //  loop through rows
    for (int cur_row = 0; cur_row < num_of_rows; cur_row++)
    {
        // and cols
        for (int cur_col = 0; cur_col < num_of_cols; cur_col++)
        {
            // print current position
            std::cout << grid[cur_row][cur_col];
            // if cur col isnt the final col, leave whitespace
            // stops trailing whitespace
            if (cur_col < num_of_cols - 1)
            {
                std::cout << " ";
            }
        }
        // new line
        std::cout << "\n";
    }
}
