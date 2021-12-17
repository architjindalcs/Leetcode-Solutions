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
    unordered_set<int> st;
    vector<TreeNode*> ans;
    void helper(TreeNode* root,TreeNode* parent){
        if(!root) return;
        helper(root->left,root);
        helper(root->right,root);
        if(st.count(root->val)){
            //i need to delete this node..
            if(parent){
                if(parent->left==root) parent->left=NULL;
                else if(parent->right==root) parent->right=NULL;
            }
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        st=unordered_set<int> (to_delete.begin(),to_delete.end());
        helper(root,NULL);
        if(!st.count(root->val)) ans.push_back(root);
        return ans;
    }
};