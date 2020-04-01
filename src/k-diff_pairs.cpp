//
// Created by zawawy on 4/9/19.
//

/* Problem Statement:
 * Given an array of integers and an integer k,
 * you need to find the number of unique k-diff pairs in the array.
 * Here a k-diff pair is defined as an integer pair (i, j),
 * where i and j are both numbers in the array and their absolute difference is k.
 *
 * Find examples and more from here: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 */
#include <vector>
#include <set>
/*****Attempt 1: Not fully working yet*****/

int findPairs(std::vector<int>& nums, int k) {
    std::set<std::pair<int, int>> pairsSet;
    for (int i = 0; i < nums.size()-1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (std::abs(nums[i] - nums[j]) == k) {
                if(pairsSet.count(std::make_pair(nums[j], nums[i])) == 0)
                    pairsSet.insert(std::make_pair(nums[i], nums[j]));
            }
        }
    }
    return static_cast<int>(pairsSet.size());
}