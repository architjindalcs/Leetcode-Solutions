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
    bool helper(TreeNode* r1,TreeNode* r2){
        if(!r1 and !r2) return true;
        if(!r1 or !r2) return false;
        return r1->val==r2->val and helper(r1->left,r2->right) and helper(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(q.size()>=2){
            TreeNode* lft=q.front();
            q.pop();
            TreeNode* rht=q.front();
            q.pop();
            if(lft and rht and lft->val!=rht->val) return false;
            if(lft==NULL and rht==NULL) continue;
            if(!lft or !rht) return false;
            if(lft and rht){
                q.push(lft->left);
                q.push(rht->right);
                q.push(lft->right);
                q.push(rht->left);
            }
        }
        return true;
    }
};