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
    TreeNode* helper(vector<int>& pre,vector<int>& post,int& pI,int st,int end){
        if(pI>=pre.size()) return NULL;
        if(st>end) return NULL;
        TreeNode* nn=new TreeNode(pre[pI++]);
        if(st==end) return nn;
        int key=pre[pI];
        int idx=m[key];
        nn->left=helper(pre,post,pI,st,idx);
        nn->right=helper(pre,post,pI,idx+1,end-1);
        return nn;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        /*
            pre-> [1,2,4,5,3,6,7]
            post-> [4,5,2,6,7,3,1]
        */
        for(int i=0;i<postorder.size();i++)
            m[postorder[i]]=i;
        int pI=0;
        return helper(preorder,postorder,pI,0,preorder.size()-1);
    }
};