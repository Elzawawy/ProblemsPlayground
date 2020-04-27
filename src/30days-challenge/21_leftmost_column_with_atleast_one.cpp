/**
 * Author: Amr Elzawawy
 * Date: 21-4-2020
 * Problem Name: Leftmost Column with at Least a One, Day 21 on the 30-Days LeetCode Challenge.
 */

/* ### Problem: **Interactive problem**
 * What is a Binary Matrix ? A binary matrix means that all elements are 0 or 1.
 * What is a Row sorted Matrix ? For each individual row of the matrix, this row is sorted in non-decreasing order.
 * Required: Return leftmost column index (0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.
 * What is Interactive ? You can't access the Binary Matrix directly.
 * You may only access the matrix using a BinaryMatrix interface:
 * **BinaryMatrix.get(row, col)** returns the element of the matrix at index (row, col) (0-indexed).
 * **BinaryMatrix.dimensions()** returns a list of 2 elements [rows, cols].
 * Problem source and more about it can be found from: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/530/week-3/3306/
 *
 * ### Constraints:
 * Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.
 * Any solutions that attempt to circumvent the judge will result in disqualification.
 * rows == mat.length
 * cols == mat[i].length
 * 1 <= rows, cols <= 100
 * mat[i][j] is either 0 or 1.
 * mat[i] is sorted in a non-decreasing way.
 */
#include <climits>
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * // We can simulate it to try it locally if we want to run this file locally, otherwise it has errors.
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
#include <vector>

class Solution {
private:
    int binarySearch(BinaryMatrix& binaryMatrix, int row, int l, int r, int x)
    {
        while (l<=r) {
            int m = (l+r)/2;
            // Check if x is present at mid
            if (binaryMatrix.get(row, m)==x)
                if (m-1>=l && binaryMatrix.get(row, m-1)==x)
                    r = m-1;
                else
                    return m;
            // If x greater, ignore left half
            if (binaryMatrix.get(row, m)<x)
                l = m+1;
                // If x is smaller, ignore right half
            else
                r = m-1;
        }
        // if we reach here, then element was not present
        return INT_MAX;
    }
public:
    /** Solution 1 : Using Binary Search since it is row sorted matrix. Search for the first 1 in each row.
     * Not Accepted because it gets more calls than 1000 on big sized inputs [100*100] only.
     * @param binaryMatrix matrix that is provided on interactive environment.
     * @return the index of the column with at least one column in index or -1 when not found.
     */
    int leftMostColumnWithOneSolution1(BinaryMatrix& binaryMatrix)
    {
        std::vector<int> dimensions = binaryMatrix.dimensions();
        int rows = dimensions[0];
        int columns = dimensions[1];
        int min_col = INT_MAX, upper_bound = columns-1;

        for (int i = 0; i<rows; i++) {
            int col_index = binarySearch(binaryMatrix, i, 0, upper_bound, 1);
            min_col = std::min(min_col, col_index);
            upper_bound = min_col;
        }
        return (min_col==INT_MAX) ? -1 : min_col;
    }
    /** Solution 2: The optimal solution.
     * Start from top right position and go right or downwards based on whether its 1 or 0, that optimally decreases the number of calls.
     * Solution Runtime: 4 ms (Beats 100%)
     * Solution Memory Usage: 8.4 MB
     * @param binaryMatrix
     * @return
     */
    int leftMostColumnWithOneSolution2(BinaryMatrix& binaryMatrix)
    {
        //Solution 2: Optimal Approach.
        std::vector<int> dimensions = binaryMatrix.dimensions();
        int rows = dimensions[0], columns = dimensions[1];
        int min_col = -1, running_row = 0, running_col = columns-1;
        while (running_row<rows and running_col>=0) {
            if (binaryMatrix.get(running_row, running_col)==1) {
                min_col = running_col;
                running_col--;
            }
            else
                running_row++;
        }
        return min_col;
    }
};