//
// Created by zawawy on 4/1/20.
//

/* Problem Statement:
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * Problem source and more about it can be found from: https://leetcode.com/problems/single-number/
 *
 */

/* Solution 1: Linear Time, But have space O(n).
 * Use an extra map for frequencies counting then return the element with value =1
 * You pass one pass on nums and then pass another pass on hash map, Hashing allows this to be O(n).
 *
 * Solution 2: Linear Time, with no space.
 * Let's XOR the numbers together, Why ? XORing two identical elements gives 0 and XORing with zero gives the same element back.
 * That will mean that the only number that is not a duplicate would remain out of the operation and the rest will be zero-ed out !
 * **/

#include <vector>
#include <map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int single_num = 0;
        for (auto& num: nums)
            single_num ^= num;

        return single_num;
    }

};