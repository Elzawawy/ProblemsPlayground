/**
 * Author: Amr Elzawawy
 * Date: 9-4-2020
 * Problem Name: Backspace String Compare, Day 9 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given two strings S and T, return if they are equal when both are typed into empty text editors.
 * `#` means a backspace character.
 * Note that after backspacing an empty text, the text will continue empty.
 * Problem source and more about it can be found from: https://leetcode.com/problems/backspace-string-compare/
 */
#include <string>

class Solution {
private:
    std::string buildString(std::string str)
    {
        for (unsigned long i = 0; i<str.size(); i++)
            if (str[i]=='#') {
                str.erase(i, 1);
                if (i!=0) {
                    str.erase(i-1, 1);
                    i--;
                }
                i--;
            }
        return str;
    }
public:
    /** Solution 1: Runtime: 0 ms(beats 100%). Memory Usage: 6.2 MB (Beats 100%)
     * Build both strings and apply required changes and then check if they have the same string or no.
     * @param S first string to compare
     * @param T second string to compare
     * @return true if they are equivalent and false otherwise.
     */
    bool backspaceCompare(std::string S, std::string T)
    {
        return (buildString(std::move(S))==buildString(std::move(T)));
    }
};