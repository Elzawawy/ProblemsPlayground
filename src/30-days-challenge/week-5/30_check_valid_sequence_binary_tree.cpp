/**
 * Author: Amr Elzawawy
 * Date: 30-4-2020
 * Problem Name: Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree, Day 30 on the 30-Days LeetCode Challenge.
 */
/* ### Problem:
 * Given a binary tree where each path going from the root to any leaf form a valid sequence.
 * Required: check if a given string is a valid sequence in such binary tree.
 * We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.
 * Problem source and more about it can be found from: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/532/week-5/3315/
 *
 * ### Constraints:
 * 1 <= arr.length <= 5000
 * 0 <= arr[i] <= 9
 * Each node's value is between [0 - 9].
 */
#include <vector>
class Solution {
private:
    // Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode()
              :val(0), left(nullptr), right(nullptr) { }
      explicit TreeNode(int x)
              :val(x), left(nullptr), right(nullptr) { }
      TreeNode(int x, TreeNode* left, TreeNode* right)
              :val(x), left(left), right(right) { }
    };
    /** DFS Function
     * @param node current node in the binary tree
     * @param arr array concatenation
     * @param current_pos current position in the array of integers.
     * @return check if the sequence array as boolean value.
     */
    bool isValidSequenceFromNode(TreeNode* node, std::vector<int>& arr, int current_pos)
    {

        if (!node or current_pos==arr.size() or node->val!=arr[current_pos])
            return false;
            // When reaching at final position check if it is a leaf node.
        else if (!node->left and !node->right and node->val==arr[current_pos] and current_pos==arr.size()-1)
            return true;
        // Make RECURSIVE CALLS to left and right subtrees.
        return (isValidSequenceFromNode(node->left, arr, current_pos+1) or
                isValidSequenceFromNode(node->right, arr, current_pos+1));
    }
public:
    /** Solution 1: Depth-first search (DFS) based-algorithm.
     * Solution Runtime: 92 ms
     * Solution Memory Usage: 49.1 MB
     * @param root binary tree root.
     * @param arr an array of integers arr
     * @return check if the sequence array as boolean value.
     */
    bool isValidSequence(TreeNode* root, std::vector<int>& arr)
    {
        return isValidSequenceFromNode(root, arr, 0);
    }
};