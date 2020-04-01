//
// Created by zawawy on 4/9/19.
//

/* Problem Statement:
 * Given an integer array, you need to find one continuous subarray that
 * if you only sort this subarray in ascending order, then the whole array
 * will be sorted in ascending order, too.
 * You need to find the shortest such subarray and output its length.
 *
 * More about problem from: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 *
 */
#include <vector>
/************ Attempt 1: Sounds working but gets Runtime error***********/

int findUnsortedSubarray(std::vector<int>& nums) {
    int start = 0, finish = -1,end =0;
    if((int)nums.size() == 2) end=3;
    else end= (int)nums.size();
    for (int i = 1; i < ((int)end)-1; ++i) {
        if (nums[i] <= nums[i - 1]) {
            if(start == 0) start = i - 1;
            finish = i;
            std::swap(nums[i],nums[i-1]);
        } if (nums[i] >= nums[i + 1]) {
            if(start == 0) start = i;
            finish = i + 1;
            std::swap(nums[i],nums[i+1]);
        }

    }
    return finish - start + 1;
}
};