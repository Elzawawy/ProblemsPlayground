/**
 * Author: Amr Elzawawy
 * Date: 17-4-2020
 * Problem Name: Number Of Islands, Day 17 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 * Problem source and more about it can be found from: https://leetcode.com/problems/number-of-islands/
 *
 * ### Constraints
 * The string size will be in the range [1, 100].
 */
#include <vector>

class Solution {
private:
    /** DFS Algorithm to find one Island.
 * @param grid the grid of the world to explore.
 * @param row row index of position in grid
 * @param col column index of position in grid
 */
    void dfsFindIsland(std::vector<std::vector<char>>& grid, int row, int col)
    {
        // if you got out of the bounds of the grid
        // OR if this is not land then get out !
        if ((row<0) or (col<0) or (row>=grid.size()) or
                (col>=grid[row].size()) or (grid[row][col]!='1'))
            return;
        // mark as explored and explore all other 4 sides of the land.
        grid[row][col] = '*';
        dfsFindIsland(grid, row+1, col);
        dfsFindIsland(grid, row-1, col);
        dfsFindIsland(grid, row, col+1);
        dfsFindIsland(grid, row, col-1);
    }
public:
    /** Solution 1: DFS and BackTracking Algorithm
     * Solution Runtime: 12 ms (Beats 88.81%)
     * Solution Memory Usage: 8.5 MB (beats 100%)
     * Iterate through every element in the grid.
     * If the element is a 1, call the DFS function and increment the counter for the number of islands by 1.
     * @param grid the grid of the world to explore.
     * @return number of islands found in the mini-world.
     */
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        if (grid.empty()) return 0;
        int num_islands = 0;
        for (int i = 0; i<grid.size(); i++)
            for (int j = 0; j<grid[i].size(); j++)
                if (grid[i][j]=='1') {
                    dfsFindIsland(grid, i, j);
                    num_islands += 1;
                }
        return num_islands;
    }
};