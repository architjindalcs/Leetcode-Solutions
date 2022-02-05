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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;
        if(!root) return {};
        while(st.size()){
            TreeNode* tp=st.top();
            st.pop();
            /*
                 1
                / \ 
                2  3
                
                1
            */
            ans.push_back(tp->val);
            if(tp->left) st.push(tp->left);
            if(tp->right) st.push(tp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};