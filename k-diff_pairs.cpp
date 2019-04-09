//
// Created by zawawy on 4/9/19.
//

/* Problem Statement:
 * Given an array of integers and an integer k,
 * you need to find the number of unique k-diff pairs in the array.
 * Here a k-diff pair is defined as an integer pair (i, j),
 * where i and j are both numbers in the array and their absolute difference is k.
 *
 * Example 1:
 * Input: [3, 1, 4, 1, 5], k = 2 , Output: 2
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
 * Although we have two 1s in the input, we should only return the number of unique pairs.
 *
 */

/*****Attempt 1: Not fully working yet*****/

int findPairs(vector<int>& nums, int k) {
    set<pair<int, int>> pairsSet;
    for (int i = 0; i < nums.size()-1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (abs(nums[i] - nums[j]) == k) {
                if(pairsSet.count(make_pair(nums[j], nums[i])) == 0)
                    pairsSet.insert(make_pair(nums[i], nums[j]));
            }
        }
    }
    return static_cast<int>(pairsSet.size());
}