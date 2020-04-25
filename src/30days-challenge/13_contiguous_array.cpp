/**
 * Author: Amr Elzawawy
 * Date: 13-4-2020
 * Problem Name: Contiguous Array, Day 13 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given a binary array, find the maximum length of a contiguous sub-array with equal number of 0 and 1.
 * Problem source and more about it can be found from: https://leetcode.com/problems/contiguous-array/
 *
 * ### Constraints
 * The length of the given binary array will not exceed 50,000.
 */
#include <vector>
#include <unordered_map>
#include <cstring>

class Solution {
public:
    /** Solution 1: Brute Force Approach
     * Runtime of O(n^2)
     * @param nums array of binary digits.
     * @return
     * Gets Time Limit Exceeded on large inputs but is working fine otherwise.
     * Generate all possible sub-arrays possible and check each of them and return the max length at the end.
     */
    int findMaxLengthSolution1(std::vector<int>& nums)
    {
        int num_ones = 0;
        int num_zeros = 0;
        int max_length = 0;
        for (int i = 0; i<nums.size(); i++) {
            for (int j = i; j<nums.size(); j++) {
                if (nums[j]==0)
                    num_zeros++;
                else
                    num_ones++;

                if (num_zeros==num_ones)
                    max_length = std::max(max_length, j-i+1);
            }
            num_ones = num_zeros = 0;
        }
        return max_length;
    }

    /** Solution 2: Unordered Map Approach
     * Runtime of O(n): 164 ms (Beats 77.41%)
     * Memory Usage of O(n): 17.7 MB (Beats 100%)
     * @param nums array of bianry digits.
     * @return maximum length of the subarray
     * Improvement observed with Unordered Map than Map
     * Improvement observed with decrement loop than increment loop
     */
    int findMaxLengthSolution2(std::vector<int>& nums)
    {
        int credit = 0, max_length = 0, size = static_cast<int>(nums.size());
        std::unordered_map<int, int> credits;
        credits[0] = size;
        for (int i = size-1; i>=0; i--) {
            credit += ((nums[i]==0) ? -1 : 1);
            if (credits.count(credit)!=0)
                max_length = std::max(max_length, credits[credit]-i);
            else
                credits[credit] = i;
        }
        return max_length;
    }

    /** Solution 2: Extra Array Approach
     * Runtime of O(n): 84 ms (Beats 98.20%)
     * Memory Usage of O(n): 14.2 MB (Beats 100%)
     * @param nums array of bianry digits.
     * @return maximum length of the subarray
     */
    int findMaxLengthSolution3(std::vector<int>& nums)
    {
        unsigned long credit = nums.size();
        int max_length = 0, credits[nums.size()*2+1];
        //reserve space for the credits array.
        memset(credits, 0, (nums.size()*2+1)*sizeof(int));

        for (int i = 0; i<nums.size(); ++i) {
            credit += ((nums[i]==0) ? -1 : 1);
            if (credit==nums.size()) max_length = i+1;
            else {
                if (credits[credit]!=0)
                    max_length = std::max(max_length, i-credits[credit]+1);
                else
                    credits[credit] = i+1;
            }
        }
        return max_length;
    }
};