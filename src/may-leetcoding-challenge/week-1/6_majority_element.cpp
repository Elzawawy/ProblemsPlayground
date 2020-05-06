/**
 * Author: Amr Elzawawy
 * Date: 6-5-2020
 * Problem Name:  Majority Element, Day 6 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * Given: an array of size n. (non-empty and the majority element always exist in the array)
 * Required: the majority element.
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/majority-element/
 */
#include <unordered_map>
#include <algorithm>
#include <vector>
class Solution {
public:
    /** Solution 1: Using In-place sorting.
     * Solution Runtime O(n*lg(n)): 76 ms (Beats 5.59%)
     * Solution Memory Usage O(1) : 19.9 (Beats 6%)
     * @param nums array to look into.
     * @return  majority element.
     */
    int majorityElementSolution1(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }

    /** Solution 2: Using HashMap to store frequencies and get the element that has counts more than n/2.
     * Solution Runtime O(n): 48 ms (Beats 21.18%)
     * Solution Memory Usage O(n) : 19.7 (Beats 6%)
     * @param nums array to look into.
     * @return  majority element.
     */
    int majorityElementSolution2(std::vector<int>& nums)
    {
        int majority_size = static_cast<int>(nums.size()/2);
        std::unordered_map<int, int> count_frequencies;
        for (auto& num: nums)
            count_frequencies[num]++;
        for (auto& entry: count_frequencies)
            if (entry.second>majority_size)
                return entry.first;
        return -1;
    }
};


