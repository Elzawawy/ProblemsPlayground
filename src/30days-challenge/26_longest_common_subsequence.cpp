/**
 * Author: Amr Elzawawy
 * Date: 26-4-2020
 * Problem Name:  Longest Common Sub-sequence, Day 26 on the 30-Days LeetCode Challenge.
 */
/* ### Problem:
 * What is a sub-sequence of a string ? It is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters.
 * Example (eg, "ace" is a sub-sequence of "abcde" while "aec" is not).
 * A **common** sub-sequence of two strings is a sub-sequence that is common to both strings.
 * Given two strings text1 and text2.
 * Required: return the length of their longest common sub-sequence. If there is no common sub-sequence, return 0.
 * Problem source and more about it can be found from: https://leetcode.com/problems/longest-common-subsequence/
 *
 * ### Constraints:
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * The input strings consist of lowercase English characters only.
 */
#include <string>
#include <cstring>
class Solution {
public:
    /** Solution 1: Dynamic Programming based-Algorithm
     * DP[i][j] represents the length of the longest common sub-sequence of text1[0..i] & text2[0..j].
     * Solution Runtime: 16 ms (Beats 84.50%)
     * Solution Memory Usage: 8 MB (Beats 100%)
     * @param text1 input string one
     * @param text2 input string two
     * @return the longest commen sub-sequence of the two strings.
     */
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        // allocate and initialize dynamic programming array for solution.
        int dp[text1.size()+1][text2.size()+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i<text1.size(); i++)
            for (int j = 0; j<text2.size(); j++)
                // common letter --> add 1 to the length.
                if (text1[i]==text2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                    // non-common letter --> get the maximum of neighbours.
                else
                    dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);
        return dp[text1.size()][text2.size()];
    }
};