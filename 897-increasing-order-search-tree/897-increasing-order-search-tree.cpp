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
    TreeNode* ans;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        if(!prev){
            ans=root;
            prev=root;
        }
        else{
            prev->right=root;
            root->left=NULL;
            prev=root;
        }
        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};