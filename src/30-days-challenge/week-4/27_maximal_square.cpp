/**
 * Author: Amr Elzawawy
 * Date: 27-4-2020
 * Problem Name:  Maximal Square, Day 27 on the 30-Days LeetCode Challenge.
 */
/* ### Problem:
 * Given a 2D binary matrix filled with 0's and 1's.
 * Required: Find the largest square containing only 1's and return its area.
 * Problem source and more about it can be found from: https://leetcode.com/problems/maximal-square/
 */
#include <vector>
#include <cstring>
#define ONE '1'
class Solution {
public:
    /** Solution 1: Dynamic Programming based-Algorithm
    * DP[i][j] represents the side length of the square which this (i,j) is the bottom right corner.
    * Solution Runtime: 40 ms (Beats 16.21%)
    * Solution Memory Usage: 11 MB (Beats 62.96%)
    * @param matrix 2D Binary Matrix input
    * @return the maximum area of the square that have only 1's in matrix.
    */
    int maximalSquare(std::vector<std::vector<char>>& matrix)
    {
        // null safety check for matrix.
        if (matrix.empty())
            return 0;
        // allocate and initialize dynamic programming array for solution.
        int max_side_len = 0, dp[matrix.size()+1][matrix[0].size()+1];
        memset(dp, 0, sizeof(dp));
        // Iterate on the matrix (One Pass).
        for (int i = 1; i<=matrix.size(); i++)
            for (int j = 1; j<=matrix[0].size(); j++) {
                // Determine for each ONE in the matrix the side length of the square which this ONE is in its bottom corner.
                if (matrix[i-1][j-1]==ONE)
                    dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1]))+1;
                max_side_len = std::max(max_side_len, dp[i][j]);
            }
        return max_side_len*max_side_len;
    }
};