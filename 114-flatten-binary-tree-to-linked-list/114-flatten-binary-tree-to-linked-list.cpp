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
    TreeNode* prev=NULL;
    void helper(TreeNode* root){
       if(!root) return;
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        
        if(!prev){
            prev=root;
        }
        else{
            prev->right=root;
            prev->left=NULL;
            prev=root;
        }
        
        helper(l);
        helper(r);
    }
    void flatten(TreeNode* root) {
        helper(root);

    }
};