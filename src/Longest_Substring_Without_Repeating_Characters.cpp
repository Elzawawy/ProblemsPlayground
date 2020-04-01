//
// Created by zawawy on 3/11/20.
//

/* Problem Statement:
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Find examples and more from here: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>



class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::string currentSubstring;
        std::vector<std::string> listOfSubstrings;
        std::map<char, int> charFrequency;
        for (char c : s) {
            if(++charFrequency[c] > 1){
                std::cout<<(c)<<std::endl;
                std::cout<<(charFrequency[c])<<std::endl;
                listOfSubstrings.push_back(currentSubstring);
                charFrequency.clear();

                std::string lastPart = currentSubstring.substr(currentSubstring.find(c)+1, currentSubstring.size()-1);
                currentSubstring = lastPart+c;
                for (char c2 :currentSubstring){
                    charFrequency[c2]++;
                }
            }
            else {
                currentSubstring += c;
            }
            for (std::string snew : listOfSubstrings){
                std::cout<<snew<<std::endl;
            }
        }
        listOfSubstrings.push_back(currentSubstring);
        std::cout<<listOfSubstrings[0]<<std::endl;
        std::cout<<listOfSubstrings[1]<<std::endl;
        return static_cast<int>(max_line_length(listOfSubstrings));
    }

    struct size_less
    {
        template<class T> bool operator()(T const &a, T const &b) const
        { return a.size() < b.size(); }
    };

    static size_t max_line_length(std::vector<std::string> const &lines)
    {
        return std::max_element(lines.begin(), lines.end(), size_less())->size();
    }
};