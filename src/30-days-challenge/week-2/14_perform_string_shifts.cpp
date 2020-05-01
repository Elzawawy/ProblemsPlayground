/**
 * Author: Amr Elzawawy
 * Date: 14-4-2020
 * Problem Name: Perform String Shifts, Day 14 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * You are given a string s containing lowercase English letters,
 * and a matrix shift, where shift[i] = [direction, amount]:
 * direction can be 0 (for left shift) or 1 (for right shift).
 * amount is the amount by which string s is to be shifted.
 * A left shift by 1 means remove the first character of s and append it to the end.
 * Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
 * Return the final string after all operations.
 * Problem source and more about it can be found from LeetCode. (Currently No link as it is newly featured)
 *
 * ### Constraints
 * 1 <= s.length <= 100 ---> s only contains lower case English letters.
 * 1 <= shift.length <= 100  ---> shift[i].length == 2
 * 0 <= shift[i][0] <= 1
 * 0 <= shift[i][1] <= 100
 */
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * Solution 1: Intuitively performing all shift operations
     * Solution Runtime: 0 ms (Beats 100%)
     * Solution Memory Usage: 6.8 MB
     * @param s string to shift upon
     * @param shift the shift matrix that has the shift operations required.
     * @return string that is shifted according to shift matrix.
     */
    std::string stringShiftSolution1(std::string s, std::vector<std::vector<int>>& shift)
    {
         for (auto& i : shift) {
             // direction == left ---> lshift, iterate by amount of shifts in i[1
             if(!i[0])
                 std::rotate(s.begin(), s.begin()+i[1], s.end());
             // direction == right ---> rshift, iterate by amount of shifts.
             else
                 std::rotate(s.begin(), s.begin()+s.size()-i[1], s.end());
         }
         return s;
    }

    /**
     * Solution 1: Noticing that left shift cancels the right shift
     * Count the total left shift times (may be negative if the final result is right shift), and perform it once.
     * Solution Runtime: 0 ms (Beats 100%)
     * Solution Memory Usage: 6.8 MB
     * @param s string to shift upon
     * @param shift the shift matrix that has the shift operations required.
     * @return string that is shifted according to shift matrix.
     */
    std::string stringShiftSolution2(std::string s, std::vector<std::vector<int>>& shift)
    {
        int left_shifts= 0, right_shifts=0;
        for (auto& i : shift) {
            // direction == left ---> lshift, count the lift shifts
            if(!i[0])
                for(int j = i[1]; j>0 ;j--)
                    left_shifts++;
                // direction == right ---> rshift, count the right shifts
            else
                for(int j = i[1];j>0 ;j--)
                    right_shifts++;
        }
        int total_shifts = left_shifts - right_shifts;
        if(total_shifts > 0)
            std::rotate(s.begin(), s.begin()+abs(total_shifts), s.end());
        else
            std::rotate(s.begin(), s.begin()+s.size()-abs(total_shifts), s.end());
        return s;
    }
};