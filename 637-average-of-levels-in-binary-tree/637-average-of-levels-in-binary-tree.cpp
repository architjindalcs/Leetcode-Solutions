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
    vector<double> ans;
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(q.size()){
            int siz=q.size();
            double sum=0.0;
            double os=1.0*siz;
            while(siz--){
                TreeNode* fr=q.front();
                q.pop();
                sum+=(fr->val);
                if(fr->left) q.push(fr->left);
                if(fr->right) q.push(fr->right);
            }   
            ans.push_back(sum/os);
        }
        return ans;
    }
};