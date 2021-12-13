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
    vector<TreeNode*> helper(int st,int end){
        if(st>end) return vector<TreeNode*> {NULL};
        vector<TreeNode*> ans;
        for(int i=st;i<=end;i++){
            vector<TreeNode*> left=helper(st,i-1);
            vector<TreeNode*> right=helper(i+1,end);
            for(auto l: left){
                for(auto r: right){
                    TreeNode* nn=new TreeNode(i);
                    nn->left=l;
                    nn->right=r;
                    ans.push_back(nn);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};