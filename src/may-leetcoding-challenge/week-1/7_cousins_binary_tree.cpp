/**
 * Author: Amr Elzawawy
 * Date: 7-5-2020
 * Problem Name: Cousins in Binary Tree, Day 7 on the May LeetCoding Challenge.
 */
/* ### Problem:
 * In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
 * Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
 * We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
 * Return true if and only if the nodes corresponding to the values x and y are cousins.
 *
 * Problem Assumptions:
 * The number of nodes in the tree will be between 2 and 100.
 * Each node has a unique integer value from 1 to 100.
 * Problem source and more about it can be found from: https://leetcode.com/problems/cousins-in-binary-tree/
 */

#include <unordered_map>
#include <utility>
class Solution {
private:
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

    // Helper method for isCousins function that performs DFS on all tree nodes
    // and for each node creates a map entry with its depth and parent into the map passed to it.
    // Main Functionality: Map Tree into a map data structure with depth of node as key and parent as value.
    void treeMapper(TreeNode* node, int depth, int parent, std::unordered_map<int, std::pair<int, int>>& tree_map)
    {
        if (!node) return;
        tree_map[node->val] = std::make_pair(depth, parent);
        treeMapper(node->left, depth+1, node->val, tree_map);
        treeMapper(node->right, depth+1, node->val, tree_map);
    }
public:
    /** Solution 1 : Using DFS and Map Data Structure. (Not Optimal at all, will attempt more later)
     * Solution Runtime: 8 ms
     * Solution Memory Usage: 13.2 MB
     * @param root  pointer to the tree root node.
     * @param x first value to compare upon
     * @param y second value to compare upon
     * @return whether x and y nodes are cousins ar not.
     */
    bool isCousins(TreeNode* root, int x, int y)
    {
        std::unordered_map<int, std::pair<int, int>> tree_map;
        treeMapper(root, 0, -1, tree_map);
        return (tree_map[x].first==tree_map[y].first) and (tree_map[x].second!=tree_map[y].second);
    }
};