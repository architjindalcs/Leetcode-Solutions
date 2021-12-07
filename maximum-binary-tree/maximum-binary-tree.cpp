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
    int getIdx(vector<int>& nums,int l,int r){
        int maxm=INT_MIN,idx=-1;
        for(int i=l;i<=r;i++){
            if(nums[i]>maxm){
                maxm=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode* helper(vector<int>& nums,int l,int r){
        if(l>r) return NULL;
        int idx=getIdx(nums,l,r);
        TreeNode* nn=new TreeNode(nums[idx]);
        nn->left=helper(nums,l,idx-1);
        nn->right=helper(nums,idx+1,r);
        return nn;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};