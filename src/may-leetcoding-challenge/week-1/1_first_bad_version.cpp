/**
 * Author: Amr Elzawawy
 * Date: 1-5-2020
 * Problem Name:  First Bad Version, Day 1 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product fails the quality check.
 * Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 *
 * Given:  an API bool isBadVersion(version) which will return whether version is bad.
 * Required: Implement a function to find the first bad version.
 * Constraints: You should minimize the number of calls to the API.
 * Problem source and more about it can be found from: https://leetcode.com/problems/first-bad-version/
 */

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    /**
     * Obvious and Un-acceptable Simple Solution is to just keep asking for all numbers in range [1...n]
     * Time limit exceeded is reached of course due to the many number of calls we do.
     * @param n maximum version number
     * @return the first bad version if exists.
     */
    int firstBadVersionSolution1(int n)
    {
        for (int i = 1; i<=n; i++)
            if (isBadVersion(i))
                return i;
        return n;
    }
    /**
     * A better and correct solution is to use the fact that the range [1..n] constitutes a sorted array.
     * We can use Binary searching instead of linear searching then.
     * Solution Runtime: 0 ms (Beats 100%)
     * Solution MemoryUsage: 6 MB (Beats 100%)
     * @param n maximum version number.
     * @return the first bad version if exists.
     */
    int firstBadVersionSolution2(int n)
    {
        int left = 1, right = n;
        //  left and right eventually both meet and it must be the first bad version.
        while (left<right) {
            int mid = left+(right-left)/2;
            // all versions after mid can be discarded.
            if (isBadVersion(mid)) right = mid;
            // search in right sub-array.
            else left = mid+1;
        }
        return left;
    }
};

