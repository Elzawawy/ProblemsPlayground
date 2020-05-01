//
// Created by zawawy on 4/3/20.
//
/* Problem Statement:
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4] ----> Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 * Problem source and more about it can be found from: https://leetcode.com/problems/maximum-subarray/
 */
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

class Solution {
public:

    /** Solution 1: Time ---> O(n) - Space ---> O(1)
     *
     * We use two variables, one for the current sum value we get from the current iteration.
     * And the second is the maximum sum variable which is the best result so far (this is initially the first item in the array such that if array of one size it works)
     * We iterate once on each element in list, updating our variables using the max function from STL
     *
     * Runtime: 4 ms, faster than 98.08% of C++ online submissions for Maximum Subarray.
     *
     * Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Maximum Subarray.
     **/
    int maxSubArraySolution1(std::vector<int>& nums)
    {
        // empty vector case.
        if (nums.empty())
            return 0;
        // max_sum is the maximum value so far for the whole array. (Global Maximum)
        // current_sum is the current value ending till (i) that's why it's zero at the beginning. (Local Maximum)
        int current_sum = 0, max_sum = nums[0];
        for (auto& num: nums) {
            current_sum = std::max(num, num+current_sum);
            max_sum = std::max(current_sum, max_sum);
        }
        return max_sum;
    }
};