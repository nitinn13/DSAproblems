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
    void solve(TreeNode* root, TreeNode*& prev) {
        if (!root) return;
        
        TreeNode* rightSubtree = root->right;
        prev->right = root;   
        prev->left = nullptr; 
        prev = root; 

        solve(root->left, prev);  
        solve(rightSubtree, prev); 
    }

    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode dummy(-1);
        TreeNode* prev = &dummy;
        solve(root, prev);
    }
};
