/**
 * Author: Amr Elzawawy
 * Date: 19-4-2020
 * Problem Name: Search in Rotated Sorted Array, Day 19 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * Example (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * ### Constraints:
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */
#include <vector>

class Solution {
public:
    // Solution using binary search: O(log n) , Runtime: 0 ms Memory Usage: 6.7 MB
    /** Solution 1: Using Binary Search 2 times.
     * Solution Runtime O(log n): 4 ms (Beats 67.86%)
     * Solution Memory Usage O(1): 6.7 MB (Beats 100%)
     * @param nums array sorted in ascending order, rotated at some pivot.
     * @param target value to search for in the array.
     * @return the index of target found or -1 if not found.
     */
    int search(std::vector<int>& nums, int target)
    {
        int low = 0, high = static_cast<int>(nums.size()-1);
        // Binary search for the lowest number in the array. (this is the pivot which we rotated at)
        while (low<high) {
            int middle = (low+high)/2;
            if (nums[middle]>nums[high])
                low = middle+1;
            else
                high = middle;
        }
        // At the end of the first search ---> low = high = min_index
        int min_index = high;
        low = 0, high = static_cast<int>(nums.size()-1);
        //Usual Binary search for target, with a small tweak to start from pivot.
        while (low<=high) {
            int middle = (low+high)/2;
            int rotated_middle = static_cast<int>((middle+min_index)%nums.size());
            if (nums[rotated_middle]==target)
                return rotated_middle;
            if (nums[rotated_middle]<target)
                low = middle+1;
            else
                high = middle-1;
        }
        // if the while loop ends without return, target is not found.
        return -1;
    }
};
