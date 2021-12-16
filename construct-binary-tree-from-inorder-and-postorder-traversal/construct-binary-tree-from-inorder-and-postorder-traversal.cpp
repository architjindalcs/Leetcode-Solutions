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
    TreeNode* helper(vector<int>& in,vector<int>& post,int& pI,int inStrt,int inEnd){
        if(inStrt>inEnd) return NULL;
        int key=post[pI--];
        int idx=m[key];
        TreeNode* nn=new TreeNode(key);
        if(inStrt==inEnd) return nn;
        nn->right=helper(in,post,pI,idx+1,inEnd);
        nn->left=helper(in,post,pI,inStrt,idx-1);
        return nn;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        int pI=postorder.size()-1;
        return  helper(inorder,postorder,pI,0,postorder.size()-1);
    }
};