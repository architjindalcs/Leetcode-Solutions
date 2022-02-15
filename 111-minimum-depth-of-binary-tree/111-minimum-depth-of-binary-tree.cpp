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
    int ans=INT_MAX;
    void helper(TreeNode* root,int level){
        if(!root) return;
        if(!(root->left) and !(root->right)){
            ans=min(ans,level);
            return;
        }
        helper(root->left,level+1);
        helper(root->right,level+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        helper(root,1);
        return ans;
    }
};