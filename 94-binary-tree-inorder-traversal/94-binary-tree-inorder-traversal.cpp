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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        stack<TreeNode*> st;
        vector<int> ans;
        while(curr or st.size()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            TreeNode* tp=st.top(); st.pop();
            ans.push_back(tp->val);
            curr=tp->right;
        }
        return ans;
    }
};