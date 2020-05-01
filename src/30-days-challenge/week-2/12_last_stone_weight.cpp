/**
 * Author: Amr Elzawawy
 * Date: 12-4-2020
 * Problem Name: Last Stone Weight, Day 12 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * We have a collection of stones, each stone has a positive integer weight.
 * Each turn, we choose the two heaviest stones and smash them together.
 * Suppose the stones have weights x and y with x <= y.  The result of this smash is:
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
 * At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
 * Problem source and more about it can be found from: https://leetcode.com/problems/last-stone-weight/
 *
 * ### Constraints
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 1000
 */
#include <vector>
#include <algorithm>

/**
 * Solution Runtime: 0 ms(Beats 100%)
 * Solution Memory Usage: 6.2 MB(Beats 100%)
 * The idea of the solution is to make a maximum heap from the vector input and maintain that heap.
 * Why Heap ? Because we can get the maximum each time efficiently.
 */
class Solution {
private:
    int getMaxFromHeap(std::vector<int>& heap){
        int x = heap.front();
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        return x;
    }
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::make_heap(stones.begin(), stones.end());

        while(stones.size() > 1){
            int heaviest = getMaxFromHeap(stones);
            int second_heaviest = getMaxFromHeap(stones);

            if(heaviest != second_heaviest){
                stones.push_back(heaviest-second_heaviest);
                push_heap(stones.begin(), stones.end());
            }
        }
        return stones.empty() ? 0:stones[0];
    }
};