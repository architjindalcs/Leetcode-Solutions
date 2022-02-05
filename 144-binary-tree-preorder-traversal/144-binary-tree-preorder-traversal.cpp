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
     TreeNode* findPred(TreeNode* root){
        TreeNode* temp=root->left;
        while(temp->right and temp->right!=root) temp=temp->right;
        return temp;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;
        while(curr){
            if(!(curr->left)){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* pred=findPred(curr);
                if(!(pred->right)){
                    pred->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    pred->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};