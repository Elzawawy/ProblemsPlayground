/**
 * Author: Amr Elzawawy
 * Date: 9-5-2020
 * Problem Name:  Valid Perfect Square, Day 9 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * Given: a positive integer num
 * Required: write a function which returns True if num is a perfect square else False.
 * You may wonder is this a real problem ?
 * Well a BIG constraint here is Do not use any built-in library function such as sqrt.
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/valid-perfect-square/
 */

class Solution {
public:
    /** Solution 1: Using Binary Search since we can model a number as a sorted array from [0..num]
     * The problem becomes one of finding the perfect square root of a number using binary search in this array if exists.
     * Solution Runtime: 0 ms (Beats 100%)
     * Solution Memory Usage: 5.9 MB (Beats 100%)
     *
     * @param num number to check for perfect square condition
     * @return true if it has a perfect square root, false otherwise.
     */
    bool isPerfectSquare(int num)
    {
        // trivial two cases to return right away.
        if (num==0 || num==1)
            return static_cast<bool>(num);
        // perform binary search for the target perfect square root of a number.
        int left = 0, right = num;
        while (left<=right) {
            long mid = left+(right-left)/2;
            // a perfect square root is found !
            if (mid*mid==num)
                return true;
                // explore LEFT partition !
            else if (mid*mid<num)
                left = static_cast<int>(mid+1);
                // explore RIGHT partition !
            else
                right = static_cast<int>(mid-1);
        }
        return false;
    }
};