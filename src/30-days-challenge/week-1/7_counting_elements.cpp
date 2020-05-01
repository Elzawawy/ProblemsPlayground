/**
 * Author: Amr Elzawawy
 * Date: 7-4-2020
 * Problem Name: Counting Elements, Day 7 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given an integer array arr, count element x such that x + 1 is also in arr.
 * If there're duplicates in arr, count them separately.
 * The problem was especially featured on the LeetCode's Challenge and did not have a link yet.
 */
#include <map>
#include <vector>

class Solution {
public:
/**
 * Solution 1:
 * Runtime: 0 ms (Beats 100%), Memory Usage: 6.6 MB
 * First use a hashset to contain all elements.
 * Do another loop to count those valid elements in the array.
 */
    int countElements(std::vector<int>& arr) {
        int count =0;
        std::map<int,int> element_occurrences;
        for (int element: arr)
            element_occurrences[element]++;

        for(auto it = element_occurrences.begin(); it != element_occurrences.end(); it++)
            if((next(it,1))->first == it->first+1)
                count += it->second;
        return count;
    }
};