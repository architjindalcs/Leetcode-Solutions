class Solution {
public:
    int sum;
    long ans=INT_MIN;
    int helper(TreeNode* root,bool f){
        if(!root) return 0;
        if(f) 
            return root->val+helper(root->left,f)+helper(root->right,f);
        
        int left=helper(root->left,f);
        int right=helper(root->right,f);
        if(root->left){
            ans=max(ans,(long)left*(sum-(long)left));
        }
        if(root->right) ans=max(ans,(long)right*(sum-(long)right));
        return root->val+left+right;
    }
    int maxProduct(TreeNode* root) {
        sum=helper(root,true);
        helper(root,false);
        return ans%1000000007;
    }
};