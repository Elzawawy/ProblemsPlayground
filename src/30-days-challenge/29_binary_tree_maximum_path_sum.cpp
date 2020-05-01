/**
 * Author: Amr Elzawawy
 * Date: 29-4-2020
 * Problem Name:  Binary Tree Maximum Path Sum, Day 29 on the 30-Days LeetCode Challenge.
 */
/* ### Problem:
 * Given a non-empty binary tree, find the maximum path sum.
 * A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the root.
 * Problem source and more about it can be found from: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 */

#include <algorithm>
#include <climits>
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
    int maxPathSumFromNode(TreeNode* node, int& max_path_sum)
    {
        // BASE CASE: Leaf Nodes.
        if (!node) return 0;
        // RECURSIVE CALLS: Right and Left Subtrees.
        int left = maxPathSumFromNode(node->left, max_path_sum);
        int right = maxPathSumFromNode(node->right, max_path_sum);
        // Case 1: Node is on the path of the maximum sum with ONE or NONE of it's children.
        int max_sum_one_branch = std::max(std::max(left, right)+node->val, node->val);
        // Case 2: Node is the root of the path of the maximum sum with BOTH of it's children.
        int max_sum_till_node = std::max(max_sum_one_branch, left+right+node->val);
        // Case 3: Considering whether this Node should be included in the path of maximum sum or not at all.
        max_path_sum = std::max(max_path_sum, max_sum_till_node);
        // You return to your parent what you got from moving on path of sum !
        return max_sum_one_branch;
    }
public:
    /** Solution 1: DFS based-algorithm.
     * Solution Runtime: 44 ms (Beats 22.49%)
     * Solution Memory Usage: 28.6 MB (Beats 6.06%)
     * @param root root of the binary tree.
     * @return maximum path sum.
     */
    int maxPathSum(TreeNode* root)
    {
        int max_path_sum = INT_MIN;
        maxPathSumFromNode(root, max_path_sum);
        return max_path_sum;
    }
};