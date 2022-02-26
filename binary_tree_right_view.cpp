/*  Approach
    Use queue based level order traversal
    Iterate through the nodes at each level, popping the node and adding it's children to the queue to prep for next level
    At each level, we need the last (rightmost) node which is what someone standing on the right sees - add this to result vector
       
    Complexity
    Time - O(n)
    Space - O(n) */

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> bfs;
        TreeNode *node;
        int i, len;
        
        if (root == NULL) {
            return res;
        }
        
        bfs.push(root);
        
        while(!bfs.empty()) {  // Each iteration of this loop corresponds to a "level"
            len = bfs.size();
            for (i = 0; i < len; i++) {  //Iterate through "len" nodes ie number of nodes per level
                node = bfs.front();
                bfs.pop();
                if (node->left) {
                    bfs.push(node->left);
                }
                if (node->right) {
                    bfs.push(node->right);
                }
            }
            res.push_back(node->val); // At this point we have the last (rightmost) node of a level, push it into result
        } 
        
        return res;
    }
};
