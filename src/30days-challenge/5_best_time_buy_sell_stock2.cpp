//
// Created by zawawy on 4/5/20.
//

/* Problem Statement:
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */
/* Solution 1:
 *
 * */
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices)
    {
        int profit = 0;
        for (int i = 1; i<prices.size(); i++)
            profit+= std::max(prices[i]-prices[i-1],0);
        return profit;
    }
};