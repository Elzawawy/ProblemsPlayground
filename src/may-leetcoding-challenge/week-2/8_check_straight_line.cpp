/**
 * Author: Amr Elzawawy
 * Date: 8-5-2020
 * Problem Name:  Check If It Is a Straight Line, Day 8 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * Given: an array coordinates, where: coordinates[i] = [x, y],
 * where [x, y] represents the coordinate of a point.
 * Required: Check if these points make a straight line in the XY plane.
 *
 * ### Problem Constraints:
 * 2 <= coordinates.length <= 100
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates contains no duplicate point.
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/check-if-it-is-a-straight-line/
 */

#include <vector>
class Solution {
public:
    /** Solution 1: Using Cross product to check non-linearty.
     * Solution Runtime: 16 ms (Beats 81.91%)
     * Solution Memory Usage: 10.1 MB (Beats 100%)
     * @param coordinates set for coordinates to check if they are co-linear.
     * @return true if they are co-linear, false otherwise.
     */
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates)
    {
        if (coordinates.size()==2)
            return true;
        int y = coordinates[1][1]-coordinates[0][1];
        int x = coordinates[1][0]-coordinates[0][0];
        // iterate from third element on list and check if it is on the same line of the first 2 points and so on..
        for (int i = 2; i<coordinates.size(); i++)
            // deltaX * (newX - onLineX) != deltaY * (newY - onLineY)
            // if not equal each other then this point is non-colinear to the line between the first 2 points.
            if (x*(coordinates[i][1]-coordinates[0][1])!=y*(coordinates[i][0]-coordinates[0][0]))
                return false;
        return true;
    }
};
