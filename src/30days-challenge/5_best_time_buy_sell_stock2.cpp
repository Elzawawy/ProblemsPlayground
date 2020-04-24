/**
 * Author: Amr Elzawawy
 * Date: 5-4-2020
 * Problem Name:  Best Time to Buy and Sell , Day 5 on the 30-Days LeetCode Challenge.
 */
/* Problem Statement:
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
/** Solution 1:
 * The idea comes from Cormen's Max Sum subarray.
 * The profit is the sum of sub-profits.
 * Each sub-profit is the difference between selling at day j, and buying at day i (with j > i).
 * The range [i, j] should be chosen so that the sub-profit is maximum. (local maximum optimistically to achieve global maximum)
 */
    int maxProfit(std::vector<int>& prices)
    {
        int profit = 0;
        for (int i = 1; i<prices.size(); i++)
            profit += std::max(prices[i]-prices[i-1], 0);
        return profit;
    }
};