/**
 * Author: Amr Elzawawy
 * Date: 23-4-2020
 * Problem Name: Bitwise AND of Numbers Range, Day 23 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given a range [m, n] where 0 <= m <= n <= 2147483647.
 * Required: return the bitwise AND of all numbers in this range, inclusive.
 * Problem source and more about it can be found from: https://leetcode.com/problems/bitwise-and-of-numbers-range/
 */

class Solution {
public:
    /** Solution 1: Can we simply brute force it ? Tempting !
     * Obviously it gets TLE when full range integer number is considered [0,2147483647] as input.
     * @param m lower range
     * @param n upper range
     * @return bitwise result for all numbers in between ranges.
     */
    int rangeBitwiseAndSolution1(int m, int n)
    {
        int result = m;
        for (int i = m+1; i<=n; i++) result &= i;
        return result;
    }

    /** Solution 2: Divide And Conquer Iterative Approach.
     * The bitwise and of the range is keeping the common bits of m and n from left to right until the first bit that they are different, padding zeros for the rest.
     * @param m lower range
     * @param n upper range
     * @return bitwise result for all numbers in between ranges.
     */
    int rangeBitwiseAndSolution2(int m, int n)
    {
        int count = 0;
        // If (upper_bound> lower_bound), the final digit will never match.
        // Why ? The final digit in the binary representation changes on every increment.
        while (n>m) {
            // Shift both numbers down to the right one slot (Divide by 2 or SHR >>)
            ++count;
            m /= 2;
            n /= 2;
        }
        // When we finally find a non-zero match (two numbers that are special in the range [m, n]) (n==m = 1)
        // Then It must have occurred on the slot in the position shifted left (<< SHL) as many times as we have shifted right.
        return m << count;
    }
};