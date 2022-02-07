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
    TreeNode* helper(vector<int>& pre,int& pI,int minm,int maxm){
        if(pI>=pre.size()) return NULL;
        int key=pre[pI];
        if(key>minm and key<maxm){
            TreeNode* nn=new TreeNode(key);
            pI++;
            nn->left=helper(pre,pI,minm,key);
            nn->right=helper(pre,pI,key,maxm);
            return nn;
        }
        return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pI=0;
        return helper(preorder,pI,INT_MIN,INT_MAX);
    }
};