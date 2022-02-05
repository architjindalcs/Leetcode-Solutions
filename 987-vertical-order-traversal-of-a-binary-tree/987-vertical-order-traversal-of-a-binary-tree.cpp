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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,priority_queue<int,vector<int>,greater<int>> > > m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int level=0;
        while(q.size()){
            int siz=q.size();
            while(siz--){
                pair<TreeNode*,int> p=q.front();
                q.pop();
                TreeNode* fr=p.first;
                int c=p.second;
                int r=level;
                m[c][r].push(fr->val);
                if(fr->left)
                    q.push({fr->left,c-1});
                if(fr->right)
                    q.push({fr->right,c+1});
            }
            level++;
        }
        vector<vector<int>> ans;
        for(auto x: m){
            vector<int> temp;
            for(auto y: x.second){
                auto pq=y.second;
                while(pq.size()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};