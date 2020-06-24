/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
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
    bool isBalanced(TreeNode* root) {
        int l, r;
        
        if (root == NULL) {
            return true;
        }
        
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        
        if (abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
        return 1;
        
        return 0;
    }
    
    int maxDepth(TreeNode* root) {
        int l, r;
        
        if (root == NULL) {
            return 0;
        }
        
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        if (l > r) {
            return l+1;
        }
        else {
            return r+1;
        }
    }
};
