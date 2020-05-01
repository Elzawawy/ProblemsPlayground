/**
 * Author: Amr Elzawawy
 * Date: 22-4-2020
 * Problem Name: Sub-array Sum Equals K, Day 22 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given an array of integers and an integer k,
 * Required: Find the total number of continuous sub-arrays whose sum equals to k.
 * Problem source and more about it can be found from: https://leetcode.com/problems/subarray-sum-equals-k/
 *
 * ### Constraints:
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */
#include <vector>
#include <map>
class Solution {
public:
    /** Solution 1: Cumulative Sum Without Space Approach
     * Whenever the running_sum equals the required k value, we can update the count value.
     * We iterate over all the end indices possible for every start index.
     * Solution Runtime O(n^2): 1264 ms (Beats 11.37%)
     * Solution Memory Usage O(1): 8MB (Beats 100%)
     * @param nums array of integers
     * @param k sum of the sub-array to match.
     * @return number of sub-arrays that match the sum K.
     */
    int subarraySumSolution1(std::vector<int>& nums, int k)
    {
        int count = 0, running_sum = 0;
        for (int i = 0; i<nums.size(); i++) {
            for (int j = i; j<nums.size(); j++) {
                running_sum += nums[j];
                if (running_sum==k)
                    count++;
            }
            running_sum = 0;
        }
        return count;

    }

    /** Solution 2: Using HashMap Approach
     * Using the idea of sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1.
     * We use a map to store the cumulative sum up to all the indices possible along with the number of times the same sum occurs.
     * Solution Runtime O(n):  80 ms (Beats 35.52%)
     * Solution Memory Usage O(n): 16 MB (Beats 30.67%)
     * @param nums array of integers
     * @param k sum of the sub-array to match.
     * @return number of sub-arrays that match the sum K.
     */
    int subarraySumSolution2(std::vector<int>& nums, int k)
    {
        int count = 0, running_sum = 0;
        // Key: sum; Value: No of Occurrences of this Sum
        std::map<int, int> prefix_sum;
        prefix_sum[0]++;
        //traverse over the array nums and keep on finding the cumulative sum.
        for (int num : nums) {
            running_sum += num;
            // for every sum, we determine the number of times the sub-array with sum (k) has occurred up to this index.
            count += prefix_sum[running_sum-k];
            // create new entry if new sum or add 1 if already existing sum.
            prefix_sum[running_sum]++;
        }
        return count;
    }
};