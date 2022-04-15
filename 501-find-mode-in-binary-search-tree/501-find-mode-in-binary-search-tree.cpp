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
    unordered_map<int,int> m;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        m[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        int maxf=0;
        inorder(root);
        vector<int> ans;
        for(auto x: m){
            if(x.second>maxf){
                maxf=x.second;
                ans.clear();
                ans.push_back(x.first);
            }
            else if(x.second==maxf) ans.push_back(x.first);
        }
        return ans;
    }
    
};