//
// Created by zawawy on 4/2/20.
//
/* Problem Statement:
 * Write an algorithm to determine if a number is "happy".
 * A happy number is a number defined by the following process: Starting with any positive integer,
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 * Problem source and more about it can be found from: https://leetcode.com/problems/happy-number/
 */
/* Solution 1: Using Set
 * Runtime: 4 ms, faster than 58.22% of C++ online submissions for Happy Number.
 * Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Happy Number.
 *
 *
 * Solution 2 : Using 2 Pointers
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
 * Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Happy Number.
 * **/
#include <cmath>
#include <unordered_set>
#include <map>

class Solution {
public:
    bool isHappySolution1(int n)
    {
        int sum_digits = 0;
        std::unordered_set<int> nums_set;
        //whenever a cycle is detected get out of there and declare a sad number !
        while (nums_set.count(n)==0) {
            nums_set.insert(n);
            // break number into digits and sum them all !
            while (n>0) {
                int digit = n%10;
                n /= 10;
                sum_digits += std::pow(digit, 2);
            }
            // Yay ! Our number is happy !
            if (sum_digits==1)
                return true;
            // update the n with the new value tياo try.
            n = sum_digits;
            sum_digits = 0;
        }
        return false;
    }

    bool isHappySolution2(int n)
    {
        int total = 0, slow = n, fast = n;

        do {
            // Update slow pointer with sum of squares of digits.
            total = 0;
            n = slow;
            while (n>0) {
                total += (n%10)*(n%10);
                n = n/10;
            }
            slow = total;
            // Update fast pointer with sum of squares of digits.
            total = 0;
            n = fast;
            while (n>0) {
                total += (n%10)*(n%10);
                n = n/10;
            }
            // With fast, we need 2 operations not only one to make it ahead 1 step from slow.
            n = total;
            total = 0;
            while (n>0) {
                total += (n%10)*(n%10);
                n = n/10;
            }
            fast = total;
            // Check if any of them reached 1, then we have a happy number !
            if (slow==1 || fast==1)
                return true;

        }// Check if they reached the same value then we detect a cycle, and its a sad number !
        while (slow!=fast);

        return false;
    }
};