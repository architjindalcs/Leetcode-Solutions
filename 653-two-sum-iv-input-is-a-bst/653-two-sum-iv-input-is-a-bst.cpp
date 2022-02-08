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
    vector<int> ans;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        int l=0,r=ans.size()-1;
        while(l<r){
            int sum=ans[l]+ans[r];
            if(sum==k) return true;
            else if(sum<k) l++;
            else r--;
        }
        return false;
    }
};