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
    unordered_map<TreeNode*,int> m;
    int height(TreeNode* root){
        if(!root) return 0;
        return m[root]=1+max(height(root->left),height(root->right));
    }
    TreeNode* helper(TreeNode* root){
        if(!root) return NULL;
        int left=height(root->left);
        int right=height(root->right);
        if(left==right) return root;
        if(left<right) return helper(root->right);
        return helper(root->left);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root);
    }
};