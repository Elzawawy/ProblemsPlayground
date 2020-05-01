/**
 * Author: Amr Elzawawy
 * Date: 28-4-2020
 * Problem Name:  First Unique Number, Day 28 on the 30-Days LeetCode Challenge.
 */
/* ### Problem:
 * You have a queue of integers, you need to retrieve the first unique integer in the queue.
 * Implement the FirstUnique class:
 * FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
 * int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
 * void add(int value) insert value to the queue.
 * Problem source and more about it can be found from: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/531/week-4/3313/
 */
/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
#include <vector>
#include <queue>
#include <unordered_map>
class FirstUnique {
public:
    std::unordered_map<int, int> count_frequencies; // counter frequencies for each number.
    std::queue<int> queue_nums; //unique numbers queue.

    explicit FirstUnique(std::vector<int>& nums)
    {
        // populate both map and queue by nums vector input.
        for (int num: nums)
            // if this is not a unique number, don't push into the queue.
            if (++count_frequencies[num]==1)
                queue_nums.push(num);
    }

    int showFirstUnique()
    {   // keep popping numbers that aren't unique till we reach the first unique number.
        while (!queue_nums.empty() and count_frequencies[queue_nums.front()]>1)
            queue_nums.pop();
        return (queue_nums.empty()) ? -1 : queue_nums.front();
    }

    void add(int value)
    {
        // if this is a unique number, push into the unique numbers queue.
        if (++count_frequencies[value]==1)
            queue_nums.push(value);
    }
};
