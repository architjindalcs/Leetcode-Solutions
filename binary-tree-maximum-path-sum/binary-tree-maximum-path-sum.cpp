class Solution {
public:
    int maxm=INT_MIN;
    int helper(TreeNode* root){
        if(!root) return 0;
        int left=helper(root->left),right=helper(root->right);
        left=max(0,left); right=max(0,right);
        maxm=max(maxm,root->val+left+right);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxm;
    }
};