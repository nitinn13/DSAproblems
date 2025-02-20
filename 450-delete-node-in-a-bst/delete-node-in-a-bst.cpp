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
    TreeNode* maxele(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val== key){
            if(root->left==NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL && root->right==NULL){
                TreeNode* child = root->left;
                delete root;
                return child;

            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* child = root->right;
                delete root;
                return child;
            }
            else{
                TreeNode* maxi = maxele(root->left);
                root->val = maxi->val;
                root->left = deleteNode(root->left, maxi->val);
                return root;
            }
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);

        }
        else{
            root->left= deleteNode(root->left,key);
        }
        return root;
    }
};