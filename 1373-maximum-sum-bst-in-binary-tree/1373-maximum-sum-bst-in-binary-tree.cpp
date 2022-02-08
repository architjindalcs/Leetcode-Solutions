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
class Info{
    public:
    bool bst;
    int minm;
    int maxm;
    int maxSum;
    int mySum;
};
void print(Info ret){
}
class Solution {
public:
    int ans=INT_MIN;
    Info helper(TreeNode* root){
        if(!root) return {true,INT_MAX,INT_MIN,0,0};
        if(!(root->left) and !(root->right)){
             ans=max(ans,root->val);
             return {true,root->val,root->val,root->val,root->val};
        }
           
        /*
         we basically sees root->val>left->maxm 
            and root->val<right->minm so minm we are setting as INT_MAX
            and maxm we are setting as INT_MIN
        */
        Info left=helper(root->left);
        Info right=helper(root->right);
        Info ret;
        ret.bst=false;
        ret.mySum=root->val+ left.mySum+ right.mySum;
        ret.minm=INT_MAX; ret.maxm=INT_MIN;
        
        if(root->val>left.maxm and root->val<right.minm and left.bst and right.bst){
            ret.bst=true;
            ans=max(ans,ret.mySum);
            ret.minm=min(root->val,left.minm);
            ret.maxm=max(root->val,right.maxm);
        }
        return ret;
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return max(0,ans);
    }
};