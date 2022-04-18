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
    void insert(TreeNode* root,stack<TreeNode*>& st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;   
        insert(root,st);
        while(st.size()){
            TreeNode* tp=st.top();
            st.pop();
            k--;
            if(k==0) return tp->val;
            if(tp->right) insert(tp->right,st);
        }
        return -1;
    }
};