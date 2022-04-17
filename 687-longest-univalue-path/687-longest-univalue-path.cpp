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
    int ans=0;
    int helper(TreeNode* root, int val){
        if(!root) return 0;
        
        int left=helper(root->left,root->val);
        int right=helper(root->right,root->val);
        
        ans=max(ans,1+left+right);
        return root->val==val ? 1+max(left,right) : 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        helper(root,root->val);
        return max(0,ans-1);
    }
};