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
    TreeNode* helper(unordered_map<int,pair<int,int>>& m, int root){
        TreeNode* nn=new TreeNode(root);
        if(!m.count(root)) return nn;
        if(m[root].first==-1 and m[root].second==-1) return nn;
        
        
        if(m[root].first!=-1) {
            nn->left=helper(m,m[root].first);
        }
        if(m[root].second!=-1){
            nn->right=helper(m,m[root].second);
        }
        return nn;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<int,int>> m;
        unordered_set<int> st;
        for(vector<int>& v: descriptions){
            int par=v[0],child=v[1],left=v[2];
            if(m.count(par)==0) m[par]={-1,-1};
            st.insert(child);
            if(left) m[par].first=child;
            else  m[par].second=child;
        }
        
        int root=-1;
        for(auto x: m){
            if(!st.count(x.first)) {
                root=x.first;
                break;
            }
        }
        return helper(m,root);
    }
};