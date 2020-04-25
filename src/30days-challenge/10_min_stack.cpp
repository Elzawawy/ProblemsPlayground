/**
 * Author: Amr Elzawawy
 * Date: 10-4-2020
 * Problem Name: Min Stack, Day 10 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Problem source and more about it can be found from: https://leetcode.com/problems/min-stack/
 */

#include <climits>
#include <vector>
#include <algorithm>

/** Runtime: 40 ms (Beats 73.14%), Memory Usage: 14.3 MB (Beats 100%)
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {

private:
    /** initialize your data structure here. */
    std::vector<int> stack;
    int min_stack;
public:
    MinStack()
            :min_stack(INT_MAX) { }

    void push(int x)
    {
        stack.push_back(x);
        min_stack = std::min(min_stack,x);
    }

    void pop()
    {
        if (min_stack==stack.back()) {
            stack.pop_back();
            min_stack = *std::min_element(stack.begin(), stack.end());
        }
        else if (stack.size()==2) {
            stack.pop_back();
            min_stack = stack[0];
        }
        else
            stack.pop_back();

        if (stack.empty())
            min_stack = INT_MAX;
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return min_stack;
    }
};