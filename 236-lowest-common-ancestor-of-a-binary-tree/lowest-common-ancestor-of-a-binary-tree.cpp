/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val) return p;
        if(root->val==q->val) return q;

        TreeNode* Lans = lowestCommonAncestor(root->left,p,q);
        TreeNode* Rans = lowestCommonAncestor(root->right,p,q);

        if(Lans == NULL && Rans == NULL) return NULL;
        if(Lans != NULL && Rans == NULL) return Lans;
        if(Lans == NULL && Rans != NULL) return Rans;
        else return root;

        
    }
};