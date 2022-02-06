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
    int find(int key){
        return m[key];
    }
    TreeNode* helper(vector<int>& pre,int& pI,int st,int end){
        if(st>end) return NULL;
        if(pI>=pre.size()) return NULL;  //done 
        TreeNode* nn=new TreeNode(pre[pI++]);
        if(st==end) return nn;  //single node wala case h yeh..
        int idx=find(nn->val);
        nn->left=helper(pre,pI,st,idx-1);
        nn->right=helper(pre,pI,idx+1,end);
        return nn;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        int pI=0;
        return helper(preorder,pI,0,preorder.size()-1);
    }
};