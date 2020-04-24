/**
 * Author: Amr Elzawawy
 * Date: 6-4-2020
 * Problem Name:  Group Anagrams, Day 6 on the 30-Days LeetCode Challenge.
 */

/* ### Problem
 * Given an array of strings, group anagrams together.
 * What is anagram ?
 * It is best resembled with an example. "eat", "ate", "tea" are anagrams.
 * So, Anagrams are just strings with the same characters but placed in other positions.
 *
 * Notes about Problem:
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */
#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Solution {
public:

/**
 * Solution 1:
 * Runtime: 72 ms (Beats 73.80%), Memory Usage: 15.8 MB (Beats 100%)
 * Use a Map to store a key of common string (the sorted string) and
 * strings containing the same characters in the common string (key) as the values.
 */
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        // The map keeps track of a common string that matches with all anagrams.
        std::map<std::string, std::vector<std::string>> anagrams_map;
        for (auto& str: strs) {
            // sort the string in a copy because we still need the original.
            std::string sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            anagrams_map[sorted_str].push_back(str);
        }

        // get all values out from the map we constructed and return it.
        std::vector<std::vector<std::string>> anagrams;
        anagrams.reserve(anagrams_map.size());
        for (auto& pair: anagrams_map)
            anagrams.push_back(pair.second);
        return anagrams;
    }
};