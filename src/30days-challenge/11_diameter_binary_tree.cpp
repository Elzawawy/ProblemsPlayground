/**
 * Author: Amr Elzawawy
 * Date: 11-4-2020
 * Problem Name: Diameter of Binary tree, Day 11 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * Given a binary tree, you need to compute the length of the diameter of the tree.
 * What is that ? It is the length of the longest path between any two nodes in a tree.
 * This path may or may not pass through the root.
 * Problem source and more about it can be found from: https://leetcode.com/problems/diameter-of-binary-tree/
 */

#include <algorithm>
/**
 * Solution Runtime: 12 ms (Beats 62.88%)
 * Solution Memory Usage: 17.3 MB (Beats 100%)
 * The Solution is recursive, where tou go to left and right and explore the maximum height you can reach from each node.
 */
class Solution {
private:

    // Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode* left{};
      TreeNode* right{};
      explicit TreeNode(int x)
              :val(x), left(nullptr), right(nullptr) { }
    };

    int diameter = 0;

    int diameterFromNode(TreeNode* node)
    {
        if (!node) return 0;
        // explore left and right trees.
        int left = diameterFromNode(node->left);
        int right = diameterFromNode(node->right);
        // pick the maximum from the last diameter and both branches heights.
        diameter = std::max(diameter, left+right);
        // return the maximum of the left and right branches of each node.
        return std::max(left+1, right+1);
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        // explore all branches and store result in private member diameter.
        diameterFromNode(root);
        return diameter;
    }
};