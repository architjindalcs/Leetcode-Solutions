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
    TreeNode* c1=NULL;
    TreeNode* p1=NULL;
    TreeNode* c2=NULL;
    TreeNode* p2=NULL;
    TreeNode* curr=NULL; 
    TreeNode* prev=NULL;
    void helper(TreeNode* root,TreeNode*& prev){
        if(!root) return;
        helper(root->left,prev);
        if(!prev){
            prev=root;
        }
        else{
            if(root->val<prev->val){
                if(!c1){
                    c1=root;
                    p1=prev;
                }
                else {
                    c2=root;
                    p2=prev;
                }
            }
            prev=root;
        }
        helper(root->right,prev);
    }
    void recoverTree(TreeNode* root) {
        helper(root,prev);
        if(p2){
            swap(p1->val,c2->val);
        }
        else swap(c1->val,p1->val);
        
    }
};