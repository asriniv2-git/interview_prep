/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        int l, r;
        
        if (root == NULL) {
            return 0;
        }
        else if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        else if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }
        else if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }
        else {
            l = minDepth(root->left);
            r = minDepth(root->right);
            return (l < r) ? l+1 : r+1;
        }
    }
};
