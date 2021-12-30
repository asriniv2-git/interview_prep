/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree. */

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
    int preorderIndex = 0;
    map<int, int> inorderMap;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i;
        
        for (i = 0; i < inorder.size(); i++) {  //Build hash map for O(1) search of inorder array
            inorderMap[inorder[i]] = i; 
        }
        
        return helperBuildTree(preorder, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* helperBuildTree(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        TreeNode *root;
        int inorderIndex;
        
        if ((preorderIndex >= preorder.size()) || (left > right)) {
            return NULL;
        }
        
        root = new TreeNode(preorder[preorderIndex]);      
        inorderIndex = inorderMap[root->val];
        preorderIndex++;
        
        root->left = helperBuildTree(preorder, inorder, left, inorderIndex-1);
        root->right = helperBuildTree(preorder, inorder, inorderIndex+1, right);
        
        return root;
    }
};
