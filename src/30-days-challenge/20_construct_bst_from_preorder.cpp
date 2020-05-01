/**
 * Author: Amr Elzawawy
 * Date: 20-4-2020
 * Problem Name: Construct Binary Search Tree from Pre-order Traversal, Day 20 on the 30-Days LeetCode Challenge.
 */

/* ### Problem:
 * What is BST (Binary Search Tree) ?
 * A BST is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.
 * What is Pre-order Traversal ?
 * A pre-order traversal displays the value of the node first, then traverses node.left, then traverses node.right.
 * Required: Return the root node of a binary search tree that matches the given preorder traversal.
 *
 * Problem source and more about it can be found from: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 *
 * ### Constraints:
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
 */
#include <vector>
#include <climits>
class Solution {
private:
    // Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      explicit TreeNode(int x)
              :val(x), left(nullptr), right(nullptr) { }
    };
public:

    TreeNode* recursiveSolution(std::vector<int> preorder, int upper_bound)
    {
        static int root_index = 0;
        // BASE CASE: check the tree boundaries and UPPER BOUND limits.
        if (root_index>=preorder.size() or preorder[root_index]>upper_bound)
            return nullptr;
        auto root = new TreeNode(preorder[root_index++]);
        // the upper bound for the left subtree must follow the BST rules where node.left < node.parent
        root->left = recursiveSolution(preorder, root->val);
        // the upper bound for the right subtree is the maximum possible where it follows that node.right > node.parent.
        root->right = recursiveSolution(preorder, upper_bound);
        return root;
    }
    /** Solution 1: Pass the parent root node to the recursive function to generate the left and right sub-trees.
     * Solution Runtime O(n): 8 ms (Beats 40.60%)
     * Solution Memory Usage : 15.8 MB (Beats 9.52%) --> Improvement can be made if using iterators instead of vectors directly.
     * @param preorder preorder traversal of a BST that is not constructed in memory yet.
     * @return BST Root Node from the preorder traversal.
     */
    TreeNode* bstFromPreorder(std::vector<int>& preorder)
    {
        return recursiveSolution(preorder, INT_MAX);
    }
};