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
    TreeNode* helper(vector<int>& post,int& pI,int st,int end){
        if(st>end) return NULL;
        TreeNode* nn=new TreeNode(post[pI--]);
        if(st==end) return nn;   //post-> left right root, in -> left root right
        
        int inIdx=m[nn->val];
        nn->right=helper(post,pI,inIdx+1,end);
        nn->left=helper(post,pI,st,inIdx-1);
        return nn;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        int pI=inorder.size()-1;
        return helper(postorder,pI,0,inorder.size()-1);
    }
};