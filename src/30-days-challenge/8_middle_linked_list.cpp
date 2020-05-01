/**
 * Author: Amr Elzawawy
 * Date: 8-4-2020
 * Problem Name: Middle of the Linked List, Day 8 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given a non-empty, singly linked list with head node head, return a middle node of linked list.
 * If there are two middle nodes, return the second middle node.
 * Problem source and more about it can be found from: https://leetcode.com/problems/middle-of-the-linked-list/
 */

class Solution {
private:
    //Definition for singly-linked list.
    struct ListNode {
      int val;
      ListNode* next;
      explicit ListNode(int x)
              :val(x), next(nullptr) { }
    };

public:
/**
 * Solution 1:
 * Runtime: 0 ms (Beats 100%), Memory Usage: 6.3 MB (Beats 100%)
 * Do one loop till NULL is found to get the whole size of list.
 * Do another loop till you reach the middle element indicated by the size you acquired.
 */
    ListNode* middleNode(ListNode* head)
    {
        int size = 0;
        // get the size of the linked list.
        ListNode* running = head;
        while (running!=nullptr) {
            size++;
            running = running->next;
        }
        // escape till the middle of list and return where you stop.
        int i = 0;
        size = size/2;
        running = head;
        while (i!=size) {
            i++;
            running = running->next;
        }
        return running;
    }
};
