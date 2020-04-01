//
// Created by zawawy on 4/9/19.
//

/* Two related problems about Cycles in Lists.
 * First Method returns if a cycle exists or not in general.
 * Second Method returns (if a cycle exits) the position or element it is cycles on.
 *
 * More about 1 can be found from: https://leetcode.com/problems/linked-list-cycle/
 * More about 2 can be found from: https://leetcode.com/problems/linked-list-cycle-ii/submissions/
 *
 */

#include <variant>
// Definition for singly-linked list.
typedef struct ListNode {
      int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
}ListNode;

bool hasCycle(ListNode *head) {
    while (head != nullptr) {
        if (head == head->next) {
            return true;
        }
        std::swap(head, head->next);
    }
    return false;
}

ListNode *detectCycle(ListNode *head) {
    auto slow = head, fast = head;
    do {
        if (fast ==nullptr) return nullptr;
        fast = fast->next;
        if (fast == nullptr) return nullptr;
        fast = fast->next;
        slow = slow->next;
    } while (fast != slow);
    fast = head;
    while (slow != fast) slow = slow->next, fast = fast->next;
    return fast;

}

