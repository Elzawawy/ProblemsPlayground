/**
 * Author: Amr Elzawawy
 * Date: 5-5-2020
 * Problem Name:  First Unique Character In String, Day 5 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * Given: a string (assume the string contain only lowercase letters).
 * Required: Find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/first-unique-character-in-a-string/
 */

#include <unordered_map>
class Solution {
public:
    /** Solution 1: Using HashMap to store counts for each character.
     * Solution Runtime: 104 ms (Beats 32.17%)
     * Solution Memory Usage: 10.7 (Beats 100%)
     * @param s string
     * @return index of first unique character in string.
     */
    int firstUniqChar(std::string s)
    {
        std::unordered_map<char, int> count_frequencies;
        // count for each character in the string.
        for (char i : s)
            ++count_frequencies[i];
        // iterate again on string and find the first character that has count equals to 1.
        for (int i = 0; i<s.size(); i++)
            if (count_frequencies[s[i]]==1)
                return i;
        return -1;
    }
};