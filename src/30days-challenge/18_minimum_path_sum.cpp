/**
 * Author: Amr Elzawawy
 * Date: 18-4-2020
 * Problem Name: Minimum Path Sum, Day 18 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given a m x n grid filled with non-negative numbers.
 * Required: find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * You can only move either down or right at any point in time.
 * Problem source and more about it can be found from: https://leetcode.com/problems/minimum-path-sum/
 */
#include <vector>
#include <climits>

class Solution {
private:
    int dfs(std::vector<std::vector<int>>& grid, int row, int col, int sum_so_far)
    {
        if (row==grid.size()-1 and col==grid[row].size()-1)
            return sum_so_far+grid[row][col];

        int min_right = INT_MAX, min_down = INT_MAX;
        if (col+1<grid[row].size())
            min_right = dfs(grid, row, col+1, sum_so_far+grid[row][col]);
        if (row+1<grid.size())
            min_down = dfs(grid, row+1, col, sum_so_far+grid[row][col]);

        return std::min(min_right, min_down);
    }
public:
    /** Solution 1: Using DFS (Exploring all Paths)
     * Problem : Gets TLE (Time Limit Exceeded) on large inputs ! But works fine locally otherwise.
     * @param grid non-negative numbers grid to get the minimum path sum.
     * @return the minimum path sum out of the grid.
     */
    int minPathSumSolution1(std::vector<std::vector<int>>& grid)
    {
        return dfs(grid, 0, 0, 0);
    }

    /** Solution 2
     * Solution Runtime: 8 ms (Beats 85.27%)
     * Solution Memory Usage: 8.2 MB (Beats 100%)
     * @param grid non-negative numbers grid to get the minimum path sum.
     * @return the minimum path sum out of the grid.
     */
    int minPathSumSolution2(std::vector<std::vector<int>>& grid)
    {
        // fixing row 0 and moving right, calculate the cost sum to go to that position only from right.
        for (int col = 1; col<grid[0].size(); col++)
            grid[0][col] += grid[0][col-1];
        for (int row = 1; row<grid.size(); row++) {
            grid[row][0] += grid[row-1][0];

            for (int col = 1; col<grid[0].size(); col++)
                grid[row][col] += std::min(grid[row][col-1], grid[row-1][col]);
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
