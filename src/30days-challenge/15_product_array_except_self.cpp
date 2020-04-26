/**
 * Author: Amr Elzawawy
 * Date: 15-4-2020
 * Problem Name: Product of Array Except Self, Day 15 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given an array nums of n integers where n > 1.
 * Return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Problem source and more about it can be found from: https://leetcode.com/problems/product-of-array-except-self/
 *
 * ### Constraints
 * It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
 */
#include <vector>

class Solution {
public:
    /** Solution 1: Using Intuitive DIVISION Algorithm
     * Solution Runtime: O(n) , 40 ms (Beats 79.44%)
     * Solution Memory Usage: O(1), 10.4 MB (Beats 100%). It's O(n) if we count the output array size.
     * @param nums array of n integers
     * @return array output required from problem statement.
     */
    std::vector<int> productExceptSelfSolution1(std::vector<int>& nums)
    {
        int all_product = 1, num_zeros = 0;
        std::vector<int> output(nums.size());
        // find if there is a zero element and get the product of all elements.
        for (auto& num : nums) {
            if (!num)
                num_zeros++;
            else
                all_product *= num;
        }
        // calculate the output vector.
        for (int i = 0; i<nums.size(); i++) {
            if (!num_zeros)
                output[i] = all_product/nums[i];
            else {
                if (nums[i]==0 and num_zeros<=1)
                    output[i] = all_product;
                else
                    output[i] = 0;
            }
        }
        return output;
    }

    /** Solution 1: Using Using Left and Right Arrays Algorithm
    * Solution Runtime: O(n) , 44 ms (Beats 27.50%)
    * Solution Memory Usage: O(n), 10.7 MB (Beats 100%)
    * @param nums array of n integers
    * @return array output required from problem statement.
    */
    std::vector<int> productExceptSelfSolution2(std::vector<int>& nums)
    {
        std::vector<int> left(nums.size()), right(nums.size()), output(nums.size());
        // construct left vector, we calculate the product of the elements to the left of each element.
        left[0] = 1;
        for (int i = 1; i<nums.size(); i++)
            left[i] = left[i-1]*nums[i-1];

        // construct right vector, we calculate the product of the elements to the right of each element.
        right[nums.size()-1] = 1;
        for (int i = static_cast<int>(nums.size()-2); i>=0; i--)
            right[i] = right[i+1]*nums[i+1];

        // construct output vector, by multiplying both product of left and product of right elemnts.
        for (int i = static_cast<int>(nums.size()-1); i>=0; i--)
            output[i] = left[i]*right[i];

        return output;
    }
};