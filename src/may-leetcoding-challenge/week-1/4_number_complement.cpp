/**
 * Author: Amr Elzawawy
 * Date: 4-5-2020
 * Problem Name:  Number Complement, Day 4 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * Given: a positive integer
 * Required: its complement number.
 * The complement strategy is to flip the bits of its binary representation.
 * The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * You could assume no leading zero bit in the integer’s binary representation.
 * Problem source and more about it can be found from: https://leetcode.com/problems/number-complement/
 */

#include <bitset>
#define INT_SIZE sizeof(int) * 8
class Solution {
public:
    /** Solution 1: Using number of leading zeros.
     * The idea of my solution is to get the number of leading zeros of the `num` input.
     * We then can iterate on the specific bits that represent actual integer value and flip only those.
     * Solution Runtime: 0 ms (Beats 100%)
     * Solution Memory Usage: 5.9 (Beats 100%)
     * @param num the number to get complement of
     * @return complement of num input.
     */
    int findComplement(int num)
    {
        std::bitset<INT_SIZE> binaryStream(static_cast<unsigned long long int>(num));
        // Equivalent to 10000000 00000000 00000000 00000000
        int msb = 1 << (INT_SIZE-1), count = 0;
        // Iterate over each bit
        for (int i = 0; i<INT_SIZE; i++) {
            // If leading set bit is found, terminate the loop.
            if ((num << i) & msb)
                break;
            count++;
        }
        for (int i = 0; i<INT_SIZE-count; i++)
            binaryStream[i] = ~binaryStream[i];
        // convert binary stream into integer and return its value.
        return static_cast<int>(binaryStream.to_ulong());
    }
};