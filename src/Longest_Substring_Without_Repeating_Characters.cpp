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

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string currentSubstring;
        vector<string> listOfSubstrings;
        map<char, int> charFrequency;
        for (char c : s) {
            if(++charFrequency[c] > 1){
                cout<<(c)<<endl;
                cout<<(charFrequency[c])<<endl;
                listOfSubstrings.push_back(currentSubstring);
                charFrequency.clear();

                string lastPart = currentSubstring.substr(currentSubstring.find(c)+1, currentSubstring.size()-1);
                currentSubstring = lastPart+c;
                for (char c2 :currentSubstring){
                    charFrequency[c2]++;
                }
            }
            else {
                currentSubstring += c;
            }
            for (string snew : listOfSubstrings){
                cout<<snew<<endl;
            }
        }
        listOfSubstrings.push_back(currentSubstring);
        cout<<listOfSubstrings[0]<<endl;
        cout<<listOfSubstrings[1]<<endl;
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