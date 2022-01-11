/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105 */

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        
        inOrder(root, nums);
        
        return arrayToBST(nums, 0, nums.size()-1);
    }
    
    void inOrder(TreeNode* root, vector<int> &nums) {
        if (root == NULL) {
            return;
        }
        
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
        
        return;
    }
    
    TreeNode* arrayToBST(vector<int> nums, int left, int right) {
        int mid;
        TreeNode* root;
        
        if (left > right) {
            return NULL;
        }
        
        mid = (left+right)/2;        
        root = new TreeNode(nums[mid]);
        root->left = arrayToBST(nums, left, mid-1);
        root->right = arrayToBST(nums, mid+1, right);
        
        return root;
    }

};
