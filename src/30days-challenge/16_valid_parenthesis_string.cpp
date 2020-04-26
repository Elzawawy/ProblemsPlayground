/**
 * Author: Amr Elzawawy
 * Date: 16-4-2020
 * Problem Name: Valid Parenthesis String, Day 16 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid.
 * We define the validity of a string by these rules:
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
 * An empty string is also valid.
 * Problem source and more about it can be found from: https://leetcode.com/problems/product-of-array-except-self/
 *
 * ### Constraints
 * The string size will be in the range [1, 100].
 */
#include <string>
#include <algorithm>
class Solution {
public:
    /** Solution 1: Greedy Algorithm, try out the asterisk as both options till a rule is broken, otherwise its valid.
     * Solution Runtime: 0-4 ms (Beats 100%)
     * Solution Memory Usage: 6 MB (Beats 100%)
     * @param s string to check for parenthesis validity rules.
     * @return boolean to indicate string validity.
     */
    bool checkValidString(std::string s)
    {   // if empty, its still valid.
        if (s.empty()) return true;
        int sum = 0;
        // count the asterisk as left parenthesis and check if the sum gets to zero.
        for (auto& character: s) {
            sum += (character=='(' or character=='*') ? 1 : -1;
            if (sum<0) return false;
        }
        // Early break to avoid trying the asterisk as right parenthesis without use.
        if (sum==0) return true;

        // count the asterisk as right parenthesis, if the sum doesn't get lower than zero then .
        sum = 0;
        std::reverse(s.begin(), s.end());
        for (auto& character: s) {
            sum += (character==')' or character=='*') ? 1 : -1;
            if (sum<0) return false;
        }
        return true;
    }
};
