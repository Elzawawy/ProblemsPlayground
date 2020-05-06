/**
 * Author: Amr Elzawawy
 * Date: 3-5-2020
 * Problem Name:  Ransom Note, Day 3 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * Given: Arbitrary ransom note string and another string containing letters from all the magazines.
 * Required: Write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 * Each letter in the magazine string can only be used once in your ransom note.
 * Both strings contain only lowercase letters.
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/ransom-note/
 */

#include <unordered_map>
class Solution {
public:
    /** Solution 1: Using a HashMap to keep track of count of characters. [We can develop we similar approach with only a vector as well]
     * Solution Runtime: 44 ms (Beats 57.94%)
     * Solution Memory Usage: 8.8 MB (Beats 100%)
     * @param ransomNote the string that has the ransom note
     * @param magazine the string that has all the characters from magazines.
     * @return whether we can re-construct ransom note from magazine or not.
     */
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::unordered_map<char, int> count_ransom(26);
        // increase the count of characters in ransom note.
        for (auto c: ransomNote)
            count_ransom[c]++;
        // for each character in the magazine string, if it is contained in the ransom decrease count.
        for (auto c: magazine)
            if (count_ransom.count(c)>0)
                // the goal here is to erase the characters when it reaches zero count.
                if (--count_ransom[c]==0)
                    count_ransom.erase(c);
        // if the ransom note can be constructed from magazine, then the counter map will be empty at the end.
        return count_ransom.empty();
    }
};
