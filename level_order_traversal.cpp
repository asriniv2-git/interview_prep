/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000 */

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        
        vector<vector<int>> res(maxDepth(root));
        
        helperLevelOrder(root, res, level);
        
        return res;
        
    }
    
    void helperLevelOrder(TreeNode* root, vector<vector<int>> &res, int level) {
        if (root == NULL) {
            return;
        }
        
        res[level++].push_back(root->val);
        
        helperLevelOrder(root->left, res, level);
        helperLevelOrder(root->right, res, level);
        
        return;
    }
    
    int maxDepth(TreeNode* root) {
        int l, r;
        
        if (root == NULL) {
            return 0;
        }
        
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        
        return (l > r) ? (l + 1) : (r + 1);
    }
};
