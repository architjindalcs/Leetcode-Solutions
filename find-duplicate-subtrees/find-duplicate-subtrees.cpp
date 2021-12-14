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
    unordered_map<string,vector<TreeNode*>> m;
    string helper(TreeNode* root){
        if(!root) return "X,";
        string ans=to_string(root->val)+","+helper(root->left)+helper(root->right);
        if(m[ans].size()<2)
        m[ans].push_back(root);
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string k=helper(root);
        vector<TreeNode*> ans;
        for(auto x: m){
            if(x.second.size()>=2){
                ans.push_back(x.second[0]);
            }
        }
        return ans;
    }
};