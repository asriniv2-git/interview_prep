/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int level;
        int max_depth;
        vector<vector<int>> level_order;
        
        max_depth = maxDepth(root);
        level = max_depth - 1;
        level_order.resize(max_depth);
        levelOrderBottomVec(root, level, level_order);
        
        return level_order;
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
    
    void levelOrderBottomVec(TreeNode* root, int level, vector<vector<int>>& level_order) {
        if (root == NULL) {
            return;
        }
        
        level_order[level].push_back(root->val);
        level--;
        
        levelOrderBottomVec(root->left, level, level_order);
        levelOrderBottomVec(root->right, level, level_order);
        
        return;
    }
};
