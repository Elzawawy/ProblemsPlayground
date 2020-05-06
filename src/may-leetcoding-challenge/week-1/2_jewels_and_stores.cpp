/**
 * Author: Amr Elzawawy
 * Date: 2-5-2020
 * Problem Name:  First Bad Version, Day 2 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * Given: strings J representing the types of stones that are jewels, and S representing the stones you have. Each character in S is a type of stone you have.
 * Required: You want to know how many of the stones you have are also jewels.
 * Constraints: S and J will consist of letters and have length at most 50.
 * The letters in J are guaranteed distinct, and all characters in J and S are letters.
 * Letters are case sensitive, so "a" is considered a different type of stone from "A".
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/jewels-and-stones/
 */

class Solution {
public:
    /** Solution 1: Using Hash Table Lookups.
     * Solution Runtime:  0 ms (Beats 100%)
     * Solution Memory Usage: 6.3 MB (Beats 100%)
     * @param J jewels string
     * @param S stones string
     * @return number of stones that are jewels.
     */
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> set_jewels;
        int num_jewels = 0;
        //insert jewels into an unordered_set which is basically a hash-table to make lookups of jewels O(1)
        for (auto& jewel_type: J)
            set_jewels.insert(jewel_type);
        //if a stone exists in the jewels hash-table then we increase the counter.
        for (auto& stone_type: S)
            if (set_jewels.count(stone_type)>0)
                num_jewels++;
        return num_jewels;
    }
};
