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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int siz=q.size();
            while(siz--){
                auto fr=q.front();
                if(siz==0) ans.push_back(fr->val);
                q.pop();
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }
        }
        return ans;
    }
};