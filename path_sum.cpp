/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        int sum_so_far = 0;
        
        return hasPathThisSum(root, sum_so_far, sum);
    }
    
    bool hasPathThisSum(TreeNode* root, int sum_so_far, int sum) {
        if (root == NULL) {
            return false;
        }
        sum_so_far += root->val;
        
        if (root->left == NULL && root->right == NULL) {
            if (sum_so_far == sum) {
                return true;
            }
            else {
                return false;
            }
        }
        
        return hasPathThisSum(root->left, sum_so_far, sum) || hasPathThisSum(root->right, sum_so_far, sum);
    }
};
