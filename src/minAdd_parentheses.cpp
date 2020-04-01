//
// Created by zawawy on 4/9/19.
//

/* Problem statement:
 * Given a string S of '(' and ')' parentheses,
 * we add the minimum number of parentheses ( '(' or ')', and in any positions )
 * so that the resulting parentheses string is valid.
 * Formally, a parentheses string is valid if and only if:
 * It is the empty string, or
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string.
 * Given a parentheses string, return the minimum number of parentheses
 * we must add to make the resulting string valid.
 *
 * Examples and more can be found from: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 *
 */

#include <string>
/*******Attempt 1: Accepted Solution in 8ms and 8.4 MB ********/

int minAddToMakeValid(std::string S) {
    int open =0;
    int count=0;
    for(char& c : S) {
        if(c == '('){
            open++;
            count++;
        }
        else if(open > 0 && c==')'){
            open--;
            count--;
        }
        else
            count++;
    }
    return count;
}
