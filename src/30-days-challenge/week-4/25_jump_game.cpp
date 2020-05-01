/**
 * Author: Amr Elzawawy
 * Date: 25-4-2020
 * Problem Name:  Jump Game, Day 25 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Required: Determine if you are able to reach the last index.
 * Problem source and more about it can be found from: https://leetcode.com/problems/jump-game/
 */
#include <vector>

class Solution {
public:
    /** Solution 1: Greedy Approach
     * Keep track of this left-most GOOD position as a separate variable.
     * Solution Runtime O(n): 8 ms (Beats 91.47%)
     * Solution Memory Usage O(1): 7.8 MB (Beats 100%)
     * @param nums array of non-negative integers to jump in.
     * @return boolean to indicate if I could reach last element index or not.
     */
    bool canJump(std::vector<int>& nums)
    {
        int last_good_pos = static_cast<int>(nums.size()-1);
        // Iterating right-to-left, for each position we check if there is a potential jump that reaches a GOOD index.
        // If we can reach a GOOD index, then our position is itself GOOD. Also, this new GOOD position will be the new leftmost GOOD index.
        for (int current_pos = static_cast<int>(nums.size()-1); current_pos>=0; current_pos--)
            last_good_pos = (current_pos+nums[current_pos]>=last_good_pos) ? current_pos : last_good_pos;

        // If first position is a GOOD index then we can reach the last index from the first position.
        return (last_good_pos==0);
    }
};
